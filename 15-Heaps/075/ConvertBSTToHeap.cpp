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
    que.push(NULL);

    while(!que.empty()){
        Node* temp=que.front();
        que.pop();

        if(temp==NULL){ //last level is complete
            cout<<endl;
            if(!que.empty()){
                que.push(NULL);
            }
        }
        else
        { 
            cout<<temp->data<<" ";
            if(temp->left){
                que.push(temp->left);
            }

            if(temp->right){
                que.push(temp->right);
            }
        }
    }
}

Node* FillPreorder(Node* root,vector<int> &inorderval, int &index){
    if(root==NULL){
        return NULL;
    }
    root->data = inorderval[index++];
    FillPreorder(root->left,inorderval,index);
    FillPreorder(root->right,inorderval,index);
    return root;
}

void Inorder(Node* root,vector<int> &inorderval){  //Left Node->Root Node->Right Node
    if(root==NULL){
        return;
    }

    Inorder(root->left,inorderval);
    inorderval.push_back(root->data);
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