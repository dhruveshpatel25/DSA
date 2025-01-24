/*Flatten binary tree to linked list
Given the root of a binary tree, flatten the tree into a "Linked list":

The "linked list" should use the same Node class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.
Examples:

Input: 
          1
        /   \
       2     5
      / \     \
     3   4     6
Output : 1 2 3 4 5 6 
Explanation: After flattening, the tree looks like this - 
     1
      \
       2
        \
         3
          \
           4
            \ 
             5 
              \
               6
Here, left of each node points to NULL and right contains the next node in preorder.The inorder traversal of this flattened tree is 1 2 3 4 5 6.

Input :
        1
       / \
      3   4
         /
        2
         \
          5 
Output : 
1 3 4 2 5 
Explanation : After flattening, the tree looks like this -
     1
      \
       3
        \
         4
          \
           2
            \ 
             5 
Here, left of each node points to NULL and right contains the next node in preorder.The inorder traversal of this flattened tree is 1 3 4 2 5.
https://www.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/1*/
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

//Left Node->Root Node->Right Node
void Inorder(Node* root){  
    if(root==NULL){
        return;
    }

    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

void Flatten(Node* root){

    //use current pointer on root node
    Node* curr = root;
    while(curr!=NULL){

        //check if there is left child 
        if(curr->left){

            //use predecessor pointer on left child
            Node* pred=curr->left;
            while(pred->right){

                //iterate till predecessor->right is not NULL
                pred=pred->right;
            }

            //now point the rightmost node to current pointer's right
            pred->right=curr->right;

            //now shift the current right to its left child
            curr->right=curr->left;

            //now remove the left pointer
            curr->left=NULL;
        }

        //iterate using right pointer
        curr=curr->right;
    }
}

int main() {
    Node* root = NULL;
    root = buildtree(root);

    cout << "Binary Tree before flattening:" << endl;
    Inorder(root);
    cout<<endl;

    Flatten(root);

    cout << "Binary Tree after flattening:" << endl;
    Inorder(root);
    cout<<endl;

    return 0;
}

//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1