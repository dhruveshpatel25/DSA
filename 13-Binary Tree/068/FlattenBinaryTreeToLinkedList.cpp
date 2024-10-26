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

//creation of binary tree
Node* buildtree(Node *root){
    cout<<"Enter the data: "<<endl;
    int data;
    cin>>data;
    root=new Node(data);
    if(data==-1){
        return NULL;
    }

    //cout<<"Enter the data for inserting in left of "<<data<<endl;
    root->left=buildtree(root->left);
    //cout<<"Enter the data for inserting in right of "<<data<<endl;
    root->right=buildtree(root->right);
    return root;
}

void Inorder(Node* root){  //Left Node->Root Node->Right Node
    if(root==NULL){
        return;
    }

    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

void Flatten(Node* root){
    Node* curr = root;
    while(curr!=NULL){
        if(curr->left){
            Node* pred=curr->left;
            while(pred->right){
                pred=pred->right;
            }
            pred->right=curr->right;
            curr->right=curr->left;
            curr->left=NULL;
        }
        curr=curr->left;
    }
}

int main() {
    Node* root = NULL;
    root = buildtree(root);

    cout << "Binary Tree before flattening:" << endl;
    Inorder(root);
    cout<<endl;

    Flatten(root);

    cout << "Binary Tree after flattening:" << endl;
    Inorder(root);
    cout<<endl;

    return 0;
}
