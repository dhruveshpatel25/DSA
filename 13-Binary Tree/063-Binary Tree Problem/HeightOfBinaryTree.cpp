#include<iostream>
#include<queue>
#include<stack>
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

int height(Node* root){
    if(root==NULL){
        return 0;
    }

    //recursivley iterates to left till it finds NULL
    int left = height(root->left);

    //recursivley iterates to right till it finds NULL
    int right = height(root->right);

    //calculates the maximum between two nodes
    int ans= max(left,right)+1;
    return ans;
}

int main() {
    Node* root = NULL;
    root = buildtree(root);
    cout << "Height of the binary tree is: " << height(root) << endl;
    return 0;
}

//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1