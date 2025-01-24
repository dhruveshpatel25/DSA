/*Tree Boundary Traversal
Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 
Left Boundary: This includes all the nodes on the path from the root to the leftmost leaf node. You must prefer the left child over the right child when traversing. Do not include leaf nodes in this section.
Leaf Nodes: All leaf nodes, in left-to-right order, that are not part of the left or right boundary.
Reverse Right Boundary: This includes all the nodes on the path from the rightmost leaf node to the root, traversed in reverse order. You must prefer the right child over the left child when traversing. Do not include the root in this section if it was already included in the left boundary.
Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 

Examples:

Input: root[] = [1, 2, 3, 4, 5, 6, 7, N, N, 8, 9, N, N, N, N] 
        1 
      /   \
     2     3  
    / \   / \ 
   4   5 6   7
      / \
     8   9
   
Output: [1, 2, 4, 8, 9, 6, 7, 3]

Input: root[] = [1, 2, N, 4, 9, 6, 5, N, 3, N, N, N, N 7, 8] 
            1
           /
          2
        /  \
       4    9
     /  \    \
    6    5    3
             /  \
            7     8

Output: [1, 2, 4, 6, 5, 7, 8]
Explanation:
As the root doesn't have a right subtree, the right boundary is not included in the traversal.

Input: root[] = [1, N, 2, N, 3, N, 4, N, N] 
    1
     \
      2
       \
        3
         \
          4

Output: [1, 4, 3, 2]
Explanation:
Left boundary: [1] (as there is no left subtree)
Leaf nodes: [4]
Right boundary: [3, 2] (in reverse order)
Final traversal: [1, 4, 3, 2]
https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1*/
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

void TraversalLeft(Node* root, vector<int> &ans){
    //base case and leftmost leafnode not to be included
    if((root==NULL)||(root->left==NULL && root->right==NULL)){
        return;
    }

    //push back current node
    ans.push_back(root->data);

    //recursively iterate to left
    if(root->left){
        TraversalLeft(root->left,ans);
    }
    //if left does not exist then only iterative to right
    else{
        TraversalLeft(root->right,ans);
    }
}

void TraversalLeaf(Node* root,vector<int> &ans){
    //base case
    if(root==NULL){
        return;
    }

    //only push leaf node
    if(root->left==NULL && root->right==NULL){
        ans.push_back(root->data);
        return;
    }

    //recursively iterate left subtree
    TraversalLeaf(root->left,ans);

    //recursively iterate right subtree
    TraversalLeaf(root->right,ans);
}

void TraversalRight(Node* root,vector<int> &ans){

    //base case and rightmost leafnode not to be included
    if((root==NULL)||(root->left==NULL && root->right==NULL)){
        return;
    }

    //first recursively iterate towards righmost node(except leaf node)
    if(root->right){
        TraversalRight(root->right,ans);
    }
    //only iterate if right subtree is not present
    else{
        TraversalRight(root->left,ans);
    }

    //push back in reverse order
    ans.push_back(root->data);
}

vector<int> boundaryTraversal(Node* root){
    vector<int> ans;

    //base case
    if(root==NULL){
        return ans;
    }

    //push back root node
    ans.push_back(root->data);

    //traverse left part of tree
    TraversalLeft(root->left,ans);

    //traverse left sub tree for left leaf node 
    TraversalLeaf(root->left,ans);

    //traverse right sub tree for right leaf node
    TraversalLeaf(root->right,ans);

    //traverse right part of tree
    TraversalRight(root->right,ans);

    return ans;
}

int main() {
    Node *root = NULL;
    root = buildtree(root);

    cout << "Boundary Traversal of the binary tree:" << endl;
    vector<int> result = boundaryTraversal(root);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}

//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1