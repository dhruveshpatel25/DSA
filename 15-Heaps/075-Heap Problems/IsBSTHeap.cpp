/*Is Binary Tree Heap
Given a binary tree. The task is to check whether the given tree follows the max heap property or not.
Note: Properties of a tree to be a max heap - Completeness and Value of node greater than or equal to its child.
https://www.geeksforgeeks.org/problems/is-binary-tree-heap/1*/
#include<iostream>
#include<queue>
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

//count the no.of nodes in binary tree
int countnodes(Node* root){

    //base case
    if(root==NULL){
        return 0;
    }

    //current node + nodes of left subtree + nodes of right subtree
    int ans=1+countnodes(root->left)+countnodes(root->right);
    return ans;
}

//check if it is complete binary tree or not
bool isCBT(Node* root,int index,int totalcount){

    //base case
    if(root==NULL){
        return true;
    }

    //check if the index is according to Heap condition
    if(index>=totalcount){
        return false;
    }else{ //if it is inside the count 

        // recursivly call the left subtree
        bool left=isCBT(root->left,2*index+1,totalcount);

        //recurivly call the right subtree
        bool right=isCBT(root->right,2*index+2,totalcount);

        //if both are true then return true
        return(left&&right);
    }
}

//check if it is max-heap or not
bool isMaxOrder(Node* root){

    //base case- leaf node
    if(root->left==NULL && root->right==NULL){
        return true;
    }

    //if the parent node has only left subtree
    if(root->right==NULL){

        //check the conditio if the left subtree value is smaller than the parent node
        return(root->data>root->left->data);


    }else{ //if parent node has both the nodes

        //recursivly iterate the left subtree
        bool left= isMaxOrder(root->left);

        //recursivly iterate the right subtree
        bool right= isMaxOrder(root->right);

        //if both the subtree are correct and the parent node is greater than both the child nodes then return true
        if(left && right && (root->data>root->left->data && root->data>root->right->data)){
            return true;
        }else{
            return false;
        }
    }
}

bool isHeap(Node* root){
    int index=0;
    int totalcount=countnodes(root);
    if(isCBT(root,index,totalcount) && isMaxOrder(root)){
        return true;
    }
}

int main() {
    Node *root = NULL;
    root = buildtree(root);

    // Check if the tree is a max heap
    if (isHeap(root)) {
        cout << "The binary tree is a max heap." << endl;
    } else {
        cout << "The binary tree is not a max heap." << endl;
    }

    return 0;
}
