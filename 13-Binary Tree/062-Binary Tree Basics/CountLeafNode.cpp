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

void Inorder(Node* root,int &count){  //Left Node->Root Node->Right Node
    if(root==NULL){
        return;
    }

    Inorder(root->left,count);
    if(root->left==NULL && root->right==NULL){
        count++;
    }
    Inorder(root->right,count);
}

int countLeafNode(Node* root){
    int count=0;
    Inorder(root,count);
    return count;
}

int main() {
    Node* root = NULL;
    root = buildtree(root);
    int leafCount = countLeafNode(root);
    cout << "Number of leaf nodes: " << leafCount << endl;
    return 0;
}
//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1