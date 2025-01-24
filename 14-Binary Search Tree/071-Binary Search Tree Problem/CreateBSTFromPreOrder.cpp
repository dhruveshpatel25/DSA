/*Preorder traversal of a BST
You have been given an array/list 'PREORDER' representing the preorder traversal of a BST with 'N' nodes. All the elements in the given array have distinct values.

Your task is to construct a binary search tree that matches the given preorder traversal.

A binary search tree (BST) is a binary tree data structure that has the following properties:

• The left subtree of a node contains only nodes with data less than the node’s data.
• The right subtree of a node contains only nodes with data greater than the node’s data.
• Both the left and right subtrees must also be binary search trees.
Note:

It is guaranteed that a BST can be always constructed from the given preorder traversal. Hence, the answer will always exist.
https://www.naukri.com/code360/problems/preorder-traversal-to-bst_893111*/
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

void levelOrderTraversal(Node *root){
    queue<Node*> que;
    que.push(root);

    //separator-used to separate 2 levels in tree
    que.push(NULL);

    while(!que.empty()){
        Node* temp=que.front();
        que.pop();

        //last level is complete
        if(temp==NULL){
            cout<<endl;

            //queue still has child nodes
            if(!que.empty()){
                que.push(NULL);
            }
        }
        else
        { 
            cout<<temp->data<<" ";

            //pushing the left child
            if(temp->left){
                que.push(temp->left);
            }

            //pushing the right child
            if(temp->right){
                que.push(temp->right);
            }
        }
    }
}

Node* insertToBST(Node* root,int data){
    if(root==NULL){
        root=new Node(data);
        return root;
    }

    //iterate to right if the data is greater than the root data
    if(data>root->data){
        root->right = insertToBST(root->right,data);
    }else{ 
        
    //iterate to left if the data is smaller than the root data
        root->left = insertToBST(root->left,data);
    }
    return root;
}

void takeInput(Node* &root){
    int data;
    cin>>data;

    while(data!=-1){
        root=insertToBST(root,data);
        cin>>data;
    }
}

Node* solve(vector<int> &preorder,int mini,int maxi,int &i){

    //if you are out of array
    if(i>=preorder.size()){
        return NULL;
    }

    //if the number is infinity
    if(preorder[i]<mini || preorder[i]>maxi){
        return NULL;
    }
    Node* root=new Node(preorder[i++]);

    //recursively iterate to left subtree ans the range is between mini and the previous data
    root->left = solve(preorder,mini,root->data,i);

    //recursively iterate to right subtree and the range is between maxi and the previous data
    root->right = solve(preorder,root->data,maxi,i);
    return root;
}

Node* preorderToBST(vector<int> &preorder){
    int mini=INT_MIN;
    int maxi=INT_MAX;
    int i=0;
    return solve(preorder,mini,maxi,i);
}

int main() {
    // Taking input for preorder traversal
    int n;
    cout << "Enter number of elements in preorder traversal: ";
    cin >> n;

    vector<int> preorder(n);
    cout << "Enter elements for preorder traversal: ";
    for (int i = 0; i < n; i++) {
        cin >> preorder[i];
    }

    // Constructing BST from preorder traversal
    Node* root = preorderToBST(preorder);

    // Printing level order traversal of newly constructed BST
    cout << "Level Order Traversal of Constructed BST:" << endl;
    levelOrderTraversal(root);

    return 0;
}

// 10 8 21 7 27 5 4 3 -1