/*Flatten BST To A Sorted List
Problem statement
You have been given a Binary Search Tree (BST). Your task is to flatten the given BST to a sorted list. More formally, you have to make a right-skewed BST from the given BST, i.e., the left child of all the nodes must be NULL, and the value at the right child must be greater than the current node.

A binary search tree (BST), also called an ordered or sorted binary tree, is a rooted binary tree whose internal nodes each store a value greater than all the values in the node's left subtree and less than those in its right subtree.
https://www.naukri.com/code360/problems/flatten-bst-to-a-sorted-list_1169459?leftPanelTab=0*/
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

//Left Node->Root Node->Right Node
void Inorder(Node* root,vector<int> &inorderval){  
    if(root==NULL){
        return;
    }

    Inorder(root->left,inorderval);
    inorderval.push_back(root->data);
    Inorder(root->right,inorderval);
}

Node* flatten(Node* root){
    vector<int> inorderval;

    //convert BST to inorder traversal
    Inorder(root,inorderval);
    int size=inorderval.size();

    //create new root node
    Node* newRoot = new Node(inorderval[0]);

    //current pointing new root
    Node* curr = newRoot;
    for(int i=1;i<size;i++){
        Node* temp=new Node(inorderval[i]);
        curr->left=NULL;
        curr->right=temp;
        curr=temp;
    }

    //last node
    curr->left=NULL;
    curr->right=NULL;
    return newRoot;
}

int main() {
    Node* root = NULL;

    // Taking input for the Binary Search Tree
    cout << "Enter elements for the Binary Search Tree: ";
    takeInput(root);

    // Displaying original Binary Search Tree using level order traversal
    cout << "Original Binary Search Tree (Level Order Traversal):" << endl;
    levelOrderTraversal(root);

    // Flattening the Binary Search Tree
    Node* flattenedRoot = flatten(root);

    // Displaying the flattened Binary Search Tree using level order traversal
    cout << "Flattened Binary Search Tree (Level Order Traversal):" << endl;
    levelOrderTraversal(flattenedRoot);

    return 0;
}
// 10 8 21 7 27 5 4 3 -1