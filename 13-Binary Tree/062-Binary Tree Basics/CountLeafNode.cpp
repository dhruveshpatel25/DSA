/*Count Leaf Nodes
You are given a Binary tree. You have to count and return the number of leaf nodes present in it.
A binary tree is a tree data structure in which each node has at most two children, which are referred to as the left child and the right child
A node is a leaf node if both left and right child nodes of it are NULL.
https://www.naukri.com/code360/problems/count-leaf-nodes_893055*/
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
void Inorder(Node* root,int &count){  
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