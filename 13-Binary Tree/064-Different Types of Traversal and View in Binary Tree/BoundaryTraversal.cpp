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