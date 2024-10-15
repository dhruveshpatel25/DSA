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
    int maxi;
    int mini;
    bool isBST;
    int size;
};

info solve(Node* root,int &maxSize){
    if(root==NULL){
        return {INT_MIN,INT_MAX,true,0};
    }
    info left=solve(root->left,maxSize);
    info right=solve(root->right,maxSize);

    info currNode;
    currNode.size=left.size+right.size+1;
    currNode.maxi=max(root->data,right.maxi);
    currNode.mini=min(root->data,left.mini);

    if(left.isBST && right.isBST && (root->data>left.maxi && root->data<right.mini)){
        currNode.isBST=true;
    }else{
        currNode.isBST=false;
    }

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
