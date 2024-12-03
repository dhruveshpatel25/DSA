/*Convert BST to Min Heap
Given a binary search tree which is also a complete binary tree. The problem is to convert the given BST into a Min Heap with the condition that all the values in the left subtree of a node should be less than all the values in the right subtree of the node. This condition is applied to all the nodes, in the resultant converted Min Heap. 
https://www.geeksforgeeks.org/convert-bst-min-heap/*/
#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;
    
    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

Node* insertToBST(Node* root,int data){
    if(root==NULL){
        root=new Node(data);
        return root;
    }

    if(data>root->data){
        root->right = insertToBST(root->right,data);
    }else{
        root->left = insertToBST(root->left,data);
    }
    return root;
}

void levelOrderTraversal(Node *root){
    queue<Node*> que;
    que.push(root);

    //separator-used to separate 2 levels in tree
    que.push(NULL);

    while(!que.empty()){
        Node* temp=que.front();
        que.pop();

        //last level is complete
        if(temp==NULL){ 
            cout<<endl;

            //queue still has child nodes
            if(!que.empty()){
                que.push(NULL);
            }
        }
        else
        { 
            cout<<temp->data<<" ";

            //pushing the left child
            if(temp->left){
                que.push(temp->left);
            }

            //pushing the right child
            if(temp->right){
                que.push(temp->right);
            }
        }
    }
}

//Root Node->Left Node->Right Node
//here the orignial BST values are getting replaced by inorder array
Node* FillPreorder(Node* root,vector<int> &inorderval, int &index){
    if(root==NULL){
        return NULL;
    }

    //start with root being the smallest value
    root->data = inorderval[index++];

    //iterate recursivly to left subtree
    FillPreorder(root->left,inorderval,index);

    //iterate recursivly to right subtree
    FillPreorder(root->right,inorderval,index);
    return root;
}

//Left Node->Root Node->Right Node
void Inorder(Node* root,vector<int> &inorderval){  
    if(root==NULL){
        return;
    }

    //recursivly iterate the left subtree
    Inorder(root->left,inorderval);

    //push back the value
    inorderval.push_back(root->data);

    //recursivly iterate the right subtree
    Inorder(root->right,inorderval);
}

Node* convertBSTtoHeap(Node* root){
    vector<int> inorderval;
    Inorder(root,inorderval);
    int index=0;
    FillPreorder(root,inorderval,index);
}

int main() {
    Node* root = NULL;
    int data;

    // Insert elements into the BST
    cout << "Enter elements to insert into BST (-1 to end): ";
    while (true) {
        cin >> data;
        if (data == -1) break;
        root = insertToBST(root, data);
    }

    // Convert BST to Max Heap
    convertBSTtoHeap(root);

    // Print the level order traversal of the resulting Max Heap
    cout << "Level order traversal of Max Heap: " << endl;
    levelOrderTraversal(root);

    return 0;
}