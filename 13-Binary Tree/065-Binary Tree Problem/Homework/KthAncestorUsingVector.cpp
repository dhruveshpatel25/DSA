/*Kth Ancestor in a Tree
Given a binary tree of size  n, a node, and a positive integer k., Your task is to complete the function kthAncestor(), the function should return the kth ancestor of the given node in the binary tree. If there does not exist any such ancestor then return -1.
Note:
1. It is guaranteed that the node exists in the tree.
2. All the nodes of the tree have distinct values.

Examples :
Input: k = 2, node = 4
Output: 1
Explanation:
Since, k is 2 and node is 4, so we first need to locate the node and look k times its ancestors. Here in this Case node 4 has 1 as his 2nd Ancestor aka the root of the tree.

Input: k=1, node=3
      1
    /   \
   2     3

Output: 1
Explanation: k=1 and node=3 ,kth ancestor of node 3 is 1.
https://www.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1*/
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

bool solve(Node* root, int k, vector<int>& ancestor, int node){
    if(root==NULL){
        return false;
    }
    ancestor.push_back(root->data);
    if(root->data == node || solve(root->left, k, ancestor, node) || solve(root->right, k, ancestor, node)){
        return true;
    }
    ancestor.pop_back();
    return false;
}

void kAncestor(Node* root, int k, int node){
    vector<int> ancestor;
    if(solve(root, k, ancestor, node)){
        if(k <= ancestor.size()){
            cout << k << "-th ancestor of node " << node << " is: " << ancestor[ancestor.size() - (k+1)] << endl;
        } else {
            cout << "No such ancestor exists." << endl;
        }
    } else {
        cout << "Node " << node << " not found in the tree." << endl;
    }
}

int main() {
    Node *root=NULL;
    root=buildtree(root);
    int k, node;
    cout<<"Enter the node value: ";
    cin>>node;
    cout<<"Enter the value of k: ";
    cin>>k;
    kAncestor(root, k, node);
}