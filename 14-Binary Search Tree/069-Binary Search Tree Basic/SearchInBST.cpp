/*Search In BST
There is a Binary Search Tree (BST) consisting of ‘N’ nodes. Each node of this BST has some integer data.
You are given the root node of this BST, and an integer ‘X’. Return true if there is a node in BST having data equal to ‘X’, otherwise return false.

A binary search tree (BST) is a binary tree data structure that has the following properties:
1. The left subtree of a node contains only nodes with data less than the node’s data.
2. The right subtree of a node contains only nodes with data greater than the node’s data.
3. The left and right subtrees must also be binary search trees.
Note:
It is guaranteed that all nodes have distinct data.
https://www.naukri.com/code360/problems/search-in-bst_1402878*/
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

Node* insertToBST(Node* root,int data){
    if(root==NULL){
        root=new Node(data);
        return root;
    }

    //if data is greater then the root 
    if(data>root->data){
        root->right = insertToBST(root->right,data);
    }else{ 
        
    //if data is smaller then the root
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

bool searchInBSTUsingRecursion(Node *root,int data){
    if(root==NULL){
        return false;
    }

    if(root->data==data){
        return true;
    }

    //recursively travel left
    if(root->data>data){
        searchInBSTUsingRecursion(root->left,data);
    }else{ 
        
    //recursively travel right
        searchInBSTUsingRecursion(root->right,data);
    }
}

bool searchInBSTUsingIteration(Node* root,int data){
    Node* temp=root;
    while(temp!=NULL){
        if(temp==NULL){
            return false;
        }
        if(temp->data==data){
            return true;
        }

        //iterativly travel left
        if(temp->data>data){
            temp=temp->left;
        }else{ 
            
        //iterativly travel right
            temp=temp->right;
        }
    }
    return false;
}

int main() {
    Node* root = NULL;
    
    cout << "Enter elements to insert into BST: " << endl;
    takeInput(root);
    
    int searchDataRecursion;
    cout << "Enter a value to search in BST using recursion: ";
    cin >> searchDataRecursion;
    if (searchInBSTUsingRecursion(root, searchDataRecursion)) {
        cout << searchDataRecursion << " found in BST using recursion." << endl;
    } else {
        cout << searchDataRecursion << " not found in BST using recursion." << endl;
    }

    int searchDataIteration;
    cout << "Enter a value to search in BST using iteration: ";
    cin >> searchDataIteration;
    if (searchInBSTUsingIteration(root, searchDataIteration)) {
        cout << searchDataIteration << " found in BST using iteration." << endl;
    } else {
        cout << searchDataIteration << " not found in BST using iteration." << endl;
    }

    return 0;
}
// 10 8 21 7 27 5 4 3 -1