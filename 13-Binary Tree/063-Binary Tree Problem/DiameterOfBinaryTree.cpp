/*Diameter of a Binary Tree
Given a binary tree, the diameter (also known as the width) is defined as the number of edges on the longest path between two leaf nodes in the tree. This path may or may not pass through the root. Your task is to find the diameter of the tree.

Examples:

Input: root[] = [1, 2, 3]
       1
     /  \
    2    3
Output: 2
Explanation: The longest path has 2 edges (node 2 -> node 1 -> node 3).

Input: root[] = [10, 20, 30, 40, 60]
         10
        /   \
      20    30
    /   \ 
   40   60
Output: 3
Explanation:The longest path has 3 edges (node 40 -> node 20 -> node 10 -> node 30).

Input: root[] = [5, 8, 6, 3, 7, N, 9]
           5
         /   \
       8      6
      / \      \
     3   7      9
Output: 4
Explanation: The longest path has 4 edges (node 3 -> node 8 -> node 5 -> node 6 -> node 9).
https://www.geeksforgeeks.org/problems/diameter-of-binary-tree/1*/
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

pair<int,int> Diameter(Node* root){
    if(root==NULL){
        pair<int,int> p= make_pair(0,0);
        return p;
    }

    pair<int,int> left = Diameter(root->left);
    pair<int,int> right = Diameter(root->right);

    //diameter of left subtree
    int op1=left.first;

    //diameter of right subtree 
    int op2=right.first; 

    //diameter passing through current node
    int op3=left.second+right.second+1;     

    pair<int,int> ans;

    //diameter of current node
    ans.first= max(op1,max(op2,op3)); 

    //height of the current node
    ans.second=max(left.first,right.second)+1; 
    return ans;
}

int diameter(Node* root){
    return Diameter(root).first;
}

int main() {
    Node* root = NULL;
    root = buildtree(root);
    int result = diameter(root);
    cout << "Diameter of the tree is: " << result<< endl;

    return 0;
}

//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1