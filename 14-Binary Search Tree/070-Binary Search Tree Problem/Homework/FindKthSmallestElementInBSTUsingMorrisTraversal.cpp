/*Find K-th smallest Element in BST
Problem statement
Given a binary search tree and an integer ‘K’. Your task is to find the ‘K-th’ smallest element in the given BST( binary search tree).

BST ( binary search tree) -
If all the smallest nodes on the left side and all the greater nodes on the right side of the node current node.

Example -
Order of elements in increasing order in the given BST is - { 2, 3, 4, 5, 6, 7, 8, 10 }
Suppose given ‘K = 3’ then 3rd smallest element is ‘4’.
Suppose given ‘K = 8’ then 8th smallest element is ‘10’.

Note:
1. You are not required to print the output explicitly, it has already been taken care of. Just implement the function and return the ‘K-th’ smallest element of BST.
2. You don’t need to return ‘K-th’ smallest node, return just value of that node. 
3. If ‘K-th’ smallest element is not present in BST then return -1.
https://www.naukri.com/code360/problems/find-k-th-smallest-element-in-bst_1069333*/
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

int KthSmallestUsingMorrisTraversal(Node* root,int k){
    Node* curr=root;
    int count=0;
    while(curr!=NULL){

        //if there exist no left subtree below current root node
        if(curr->left==NULL){

            //increment the count
            count++;

            //if we reach k then return the data
            if(count==k){
                return curr->data;
            }

            //move to right subtree to find greater value than the current root
            curr=curr->right;
        }else{ 
            
            //if the current root node has a left subtree
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
            }else{ 
                
                //if thread exist remove the thread
                pred->right=NULL;
                count++;
                if(count==k){
                    return curr->data;
                }
                curr=curr->right;
            }
        }
    }
}
int main() {
    Node* root = NULL;

    cout << "Enter elements to insert into the BST (terminate with -1): " << endl;
    takeInput(root);

    int k;
    cout << "Enter the value of k to find the kth smallest element: ";
    cin >> k;

    int kthSmallestElement = KthSmallestUsingMorrisTraversal(root, k);
    if (kthSmallestElement != -1) {
        cout << "The " << k << "th smallest element in the BST is: " << kthSmallestElement << endl;
    } else {
        cout << "Invalid value of k!" << endl;
    }

    return 0;
}

// 10 8 21 7 27 5 4 3 -1