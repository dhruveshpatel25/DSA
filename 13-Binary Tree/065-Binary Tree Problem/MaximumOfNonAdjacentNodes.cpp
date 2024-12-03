#include<iostream>
#include<queue>
#include<stack>
#include<map>
#include<climits>
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

pair<int,int> solve(Node* root){

    //base case
    if(root==NULL){
        pair<int,int> p=make_pair(0,0); 
        return p;
    }

    //recursively iterate left subtree
    pair<int,int> left=solve(root->left);

    //recursively iterate left subtree  
    pair<int,int> right=solve(root->right);

    // <including current node,excluding current node>
    pair<int,int>res; 

    //contains addition of including current node + excluding part of adjacent node
    res.first = root->data+left.second+right.second; 

    //contains excluding of current node and maximum value of adjacent node
    res.second=max(left.first,left.second)+max(right.first,right.second); 
    return res;
}

int getMaximum(Node* root){
    pair<int,int> ans=solve(root);
    return max(ans.first,ans.second);
}

int main() {
    Node* root = NULL;
    root = buildtree(root);

    int maxSum = getMaximum(root);
    cout << "The maximum sum of non-adjacent nodes is: " << maxSum << endl;

    return 0;
}

//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1