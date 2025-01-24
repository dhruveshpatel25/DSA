/*Height of Binary Tree
Given a binary tree, find its height.
The height of a tree is defined as the number of edges on the longest path from the root to a leaf node. A leaf node is a node that does not have any children.

Examples:

Input: root[] = [12, 8, 18, 5, 11] 
Output: 2
Explanation: One of the longest path from the root (node 12) goes through node 8 to node 5, which has 2 edges.

Input: root[] = [1, 2, 3, 4, N, N, 5, N, N, 6, 7]  
Output: 3
Explanation: The longest path from the root (node 1) to a leaf node 6 with 3 edge.
https://www.geeksforgeeks.org/problems/height-of-binary-tree/1*/
#include<iostream>
#include<queue>
#include<stack>
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