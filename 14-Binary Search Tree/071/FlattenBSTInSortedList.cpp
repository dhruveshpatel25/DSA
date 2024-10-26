#include<iostream>
#include<queue>
#include<stack>
#include<map>
#include<climits>
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

void takeInput(Node* &root){
    int data;
    cin>>data;

    while(data!=-1){
        root=insertToBST(root,data);
        cin>>data;
    }
}

void Inorder(Node* root,vector<int> &inorderval){  //Left Node->Root Node->Right Node
    if(root==NULL){
        return;
    }

    Inorder(root->left,inorderval);
    inorderval.push_back(root->data);
    Inorder(root->right,inorderval);
}

Node* flatten(Node* root){
    vector<int> inorderval;
    Inorder(root,inorderval);
    int size=inorderval.size();

    Node* newRoot = new Node(inorderval[0]);
    Node* curr = newRoot;
    for(int i=1;i<size;i++){
        Node* temp=new Node(inorderval[i]);
        curr->left=NULL;
        curr->right=temp;
        curr=temp;
    }

    curr->left=NULL;
    curr->right=NULL;
    return newRoot;
}

int main() {
    Node* root = NULL;

    // Taking input for the Binary Search Tree
    cout << "Enter elements for the Binary Search Tree: ";
    takeInput(root);

    // Displaying original Binary Search Tree using level order traversal
    cout << "Original Binary Search Tree (Level Order Traversal):" << endl;
    levelOrderTraversal(root);

    // Flattening the Binary Search Tree
    Node* flattenedRoot = flatten(root);

    // Displaying the flattened Binary Search Tree using level order traversal
    cout << "Flattened Binary Search Tree (Level Order Traversal):" << endl;
    levelOrderTraversal(flattenedRoot);

    return 0;
}
