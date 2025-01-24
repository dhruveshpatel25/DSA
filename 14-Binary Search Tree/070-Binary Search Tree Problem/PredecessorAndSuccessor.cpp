/*Predecessor And Successor In BST
You have been given a binary search tree of integers with ‘N’ nodes. You are also given 'KEY' which represents data of a node of this tree.
Your task is to return the predecessor and successor of the given node in the BST.

Note:
1. The predecessor of a node in BST is that node that will be visited just before the given node in the inorder traversal of the tree. If the given node is visited first in the inorder traversal, then its predecessor is NULL.
2. The successor of a node in BST is that node that will be visited immediately after the given node in the inorder traversal of the tree. If the given node is visited last in the inorder traversal, then its successor is NULL.
3. The node for which the predecessor and successor will not always be present. If not present, you can hypothetically assume it's position (Given that it is a BST) and accordingly find out the predecessor and successor.
4. A binary search tree (BST) is a binary tree data structure which has the following properties.
     • The left subtree of a node contains only nodes with data less than the node’s data.
     • The right subtree of a node contains only nodes with data greater than the node’s data.
     • Both the left and right subtrees must also be binary search trees.
https://www.naukri.com/code360/problems/_893049*/
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

pair<int,int> predecessorAndSuccessor(Node* root,int key){
    Node* temp=root;
    int pred=-1;
    int succ=-1;

    //iterate till we kind the key
    while(temp->data!=key){

        //iterate left till we find the key
        if(temp->data>key){

            //while iterating save the value of successor
            succ=temp->data;
            temp=temp->left;
        }else{ //iterate right if the key is greater than root->data

            //while iterating save the value of predecessor
            pred=temp->data;
            temp=temp->right;
        }
    }

    Node* leftTree = temp->left;

    //check if there could be possible right subtree to for predecessor
    while(leftTree!=NULL){
        pred=leftTree->data;
        leftTree=leftTree->right;
    }

    Node* rightTree=temp->right;

    //check if there could be possible left subtree to for successor
    while(rightTree!=NULL){
        succ=rightTree->data;
        rightTree=rightTree->left;
    }

    pair<int,int> ans=make_pair(pred,succ);
    return ans;
}

int main() {
    Node* root = NULL;

    cout << "Enter nodes to insert into the BST: " << endl;
    takeInput(root);

    cout << "Level Order Traversal of the BST:" << endl;
    levelOrderTraversal(root);

    int key;
    cout<<"Enter the key: ";
    cin>>key;
    pair<int, int> predAndSucc = predecessorAndSuccessor(root, key);
    cout << "Predecessor and Successor of " << key << ": ";
    cout << predAndSucc.first << " " << predAndSucc.second << endl;
    return 0;
}
// 10 8 21 7 27 5 4 3 -1