/*Morris traversal for Inorder
Given a Binary Tree, the task is to print its Inorder Traversal, without using recursion or stack.

Examples:

Input:
Output: [4, 2, 5, 1, 3]
Explanation: Inorder traversal (Left->Root->Right) of the tree is 4, 2, 5, 1, 3.

Input:
Output: [1, 7, 10, 8, 6, 10, 5, 6]
Explanation: Inorder traversal (Left->Root->Right) of the tree is 1, 7, 10, 8, 6, 10, 5, 6.

Approach:
Using Morris Traversal, we can traverse the tree without using stack and recursion. The idea of Morris Traversal is based on Threaded Binary Tree. In this traversal, we first create links to Inorder successor and print the data using these links, and finally revert the changes to restore original tree. Although the tree is modified through the traversal, it is reverted back to its original shape after the completion. Unlike Stack based traversal, no extra space is required for this traversal.

Follow the steps below to solve the problem:
    Initialize current as root and repeat the following steps,as long as the current node is not NULL.
    If the current does not have left childthen print current’s data and go to the right, i.e., current = current->right.
    Else, find inorder predecessor of current (rightmost node in current left subtree or node whose right child is equal to current).
        If we foundthat right child of inorder predecessor is equal to current then,
            update its the right child as NULL and print current’s data.
            Go to the right, i.e. current = current->right.
        Else
            Make current as the right child of its inorder predecessor; and
            Go to current’s left child, i.e., current = current->left.
https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion-and-without-stack/*/
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

void morrisTraversal(Node* root){
    Node* curr=root;
    
    while(curr!=NULL){

        //if there exist no left subtree below current root node
        if(curr->left==NULL){
            cout<<curr->data<<" ";

            //move to right subtree to find greater value than the current root
            curr=curr->right;

        }else{ //if the current root node has a left subtree
            Node* pred=curr->left;

            //move to right subtree of predecessor node or stop if the thread exit
            while(pred->right!=NULL && pred->right!=curr){
                pred=pred->right;
            }
            //if thread does not exist then establish a thread between the predecessor and current
            if(pred->right==NULL){
                pred->right=curr;

                //move to the left subtree of current node 
                curr=curr->left;
                
            }else{ //if thread exist remove the thread
                pred->right=NULL;
                cout<<curr->data<<" ";
                curr=curr->right;
            }
        }
    }
}

int main() {
    Node* root = NULL;
    root = buildtree(root);

    cout << "Inorder Traversal using Morris Traversal: ";
    morrisTraversal(root);
    cout << endl;

    return 0;
}