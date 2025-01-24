/*Sum Tree
Given a Binary Tree. Check for the Sum Tree for every node except the leaf node. Return true if it is a Sum Tree otherwise, return false.

A SumTree is a Binary Tree where the value of a node is equal to the sum of the nodes present in its left subtree and right subtree. An empty tree is also a Sum Tree as the sum of an empty tree can be considered to be 0. A leaf node is also considered a Sum Tree.

Examples:

Input:
    3
  /   \    
 1     2
Output: true
Explanation: The sum of left subtree and right subtree is 1 + 2 = 3, which is the value of the root node. Therefore,the given binary tree is a sum tree.

Input:
          10
        /    \
      20      30
    /   \ 
   10    10
Output: false
Explanation: The given tree is not a sum tree. For the root node, sum of elements in left subtree is 40 and sum of elements in right subtree is 30. Root element = 10 which is not equal to 30+40.

Input:
   25
  /   \    
 9     15
Output: false
https://www.geeksforgeeks.org/problems/sum-tree/1*/
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

pair<bool,int> sumTree(Node* root){
    if(root==NULL){
        pair<bool,int> p = make_pair(true,0);
        return p;
    }

    //handling leaf condition
    if(root->left==NULL && root->right==NULL){
        pair<bool,int> p = make_pair(true,root->data);
        return p;
    }

    //recursively iterate left subtree
    pair<bool,int> left= sumTree(root->left);

    //recursively iterate right subtree
    pair<bool,int> right= sumTree(root->right);

    //checking if left subtree is sumtree or not
    bool leftAns=left.first;

    //checking if right subtree is sumtree or not
    bool rightAns=right.first;

    //check the condition - root data is sum of left and right subtree
    bool codn= root->data == left.second+right.second;
    pair<bool,int> ans;

    //check if all condition are true
    if(leftAns&&rightAns&&codn){
        ans.first=true;

        //root->data + right subtree->data + left subtree->data
        ans.second=2*root->data;
    }else{
        ans.first=false;
    }
    return ans;
}

int main() {
    Node *root = NULL;
    root = buildtree(root);

    pair<bool, int> result = sumTree(root);

    if (result.first) {
        cout << "The binary tree is a sum tree." << endl;
    } else {
        cout << "The binary tree is not a sum tree." << endl;
    }

    return 0;
}
//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1