#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;

    //left subtree
    Node *left;

    //right subtree
    Node *right;
    
    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

//creation of binary tree
Node* buildtree(Node *root){
    //cout<<"Enter the data: "<<endl;
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

//Left Node->Root Node->Right Node
void Inorder(Node* root){  
    if(root==NULL){
        return;
    }

    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

//Root Node->Left Node->Right Node
void Preorder(Node* root){  
    if(root==NULL){
        return;
    }
    
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}

//Left Node->Right Node->Root Node
void Postorder(Node* root){  
    if(root==NULL){
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data<<" ";
}

int main(){
    Node *root=NULL;
    root=buildtree(root);
    cout<<"Inorder Traversal is: ";
    Inorder(root);
    cout<<endl;
    cout<<"Preorder Traversal is: ";
    Preorder(root);
    cout<<endl;
    cout<<"Postorder Traversal is: ";
    Postorder(root);
}

//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1