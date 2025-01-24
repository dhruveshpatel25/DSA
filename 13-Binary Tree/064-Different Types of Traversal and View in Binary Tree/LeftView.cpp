/*Left View of Binary Tree
You are given the root of a binary tree. Your task is to return the left view of the binary tree. The left view of a binary tree is the set of nodes visible when the tree is viewed from the left side.
If the tree is empty, return an empty list.

Examples :

Input: root[] = [1, 2, 3, 4, 5, N, N]
Output: [1, 2, 4]
Explanation: From the left side of the tree, only the nodes 1, 2, and 4 are visible.
 
Input: root[] = [1, 2, 3, N, N, 4, N, N, 5, N, N]
Output: [1, 2, 4, 5]
Explanation: From the left side of the tree, the nodes 1, 2, 4, and 5 are visible.

Input: root[] = [N]
Output: []
https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1*/
#include<iostream>
#include<queue>
#include<stack>
#include<map>
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

void solve(Node* root,vector<int> &ans,int level){
    //base case
    if(root==NULL){
        return;
    }

    //only push the first value for that particular level
    if(level==ans.size()){
        ans.push_back(root->data);
    }

    //recursively iterate left subtree first as it is left view
    solve(root->left,ans,level+1);

    //then recursively iterate right subtree 
    solve(root->right,ans,level+1);
}

vector<int> LeftView(Node* root){
    vector<int> ans;
    solve(root,ans,0);
    return ans;
}

int main() {
    Node* root = NULL;
    root = buildtree(root);

    cout << "Left view of the binary tree: ";
    vector<int> result = LeftView(root);
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}

//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1