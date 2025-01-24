/*Size of Largest BST in Binary Tree
You have been given a Binary Tree of 'N' nodes, where the nodes have integer values. Your task is to return the size of the largest subtree of the binary tree which is also a BST.

A binary search tree (BST) is a binary tree data structure which has the following properties.
• The left subtree of a node contains only nodes with data less than the node’s data.
• The right subtree of a node contains only nodes with data greater than the node’s data.
• Both the left and right subtrees must also be binary search trees.
https://www.naukri.com/code360/problems/largest-bst-subtree_893103*/
#include<iostream>
#include<queue>
#include<stack>
#include<map>
#include<climits>
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

class info{
    public:

    //for stroing maximum value
    int maxi;

    //for storing minimum value
    int mini;

    //for checking BST
    bool isBST;

    //height of the current node
    int size;
};

info solve(Node* root,int &maxSize){

    //base case
    if(root==NULL){
        return {INT_MIN,INT_MAX,true,0};
    }

    //recursivly iterate left subtree
    info left=solve(root->left,maxSize);

    //recursivly iterate right subtree
    info right=solve(root->right,maxSize);

    info currNode;

    //calculate the height of current node(height of left subtree + height of right subtree + node)
    currNode.size=left.size+right.size+1;

    //maximum value of the node so it can be used to check for above nodes
    currNode.maxi=max(root->data,right.maxi);

    //minimum value of the node so it can be used to check for above nodes
    currNode.mini=min(root->data,left.mini);

    //check if both the subtree are BST and check if the current node is greater than the left subtree and smaller than right subtree
    if(left.isBST && right.isBST && (root->data>left.maxi && root->data<right.mini)){
        currNode.isBST=true;
    }else{
        currNode.isBST=false;
    }

    //calculate the maximu height of subtree 
    if(currNode.isBST){
        maxSize=max(maxSize,currNode.size);
    }
    return currNode;
}

int largestBST(Node* root){
    int maxSize=0;
    info temp=solve(root,maxSize);
    return maxSize;
}

int main() {
    Node* root = NULL;
    root = buildtree(root);

    int largestBSTSize = largestBST(root);
    cout << "Size of the largest BST in the tree is: " << largestBSTSize << endl;

    return 0;
}
// 10 8 21 7 27 5 4 3 -1