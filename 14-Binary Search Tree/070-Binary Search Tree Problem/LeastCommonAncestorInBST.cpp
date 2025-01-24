/* LCA of Two Nodes In A BST
You are given a binary search tree of integers with N nodes. You are also given references to two nodes 'P' and 'Q' from this BST.
Your task is to find the lowest common ancestor(LCA) of these two given nodes.
The lowest common ancestor for two nodes P and Q is defined as the lowest node that has both P and Q as descendants (where we allow a node to be a descendant of itself)

A binary search tree (BST) is a binary tree data structure which has the following properties.
• The left subtree of a node contains only nodes with data less than the node’s data.
• The right subtree of a node contains only nodes with data greater than the node’s data.
• Both the left and right subtrees must also be binary search trees.
https://www.naukri.com/code360/problems/lca-in-a-bst_981280*/
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

Node* LCAInBST(Node* root, Node* node1,Node* node2){
    while(root!=NULL){

        //if both the nodes are greater then root then iterate to right
        if(root->data<node1->data && root->data<node2->data){
            root=root->right;
        }
        
        //if both the nodes are smaller then the root then iterate to left
        else if(root->data>node1->data && root->data>node2->data){
            root=root->left;
        }else{ 
        
        //return the root
            return root;
        }
    }
}

int main() {
    Node* root = NULL;
    cout << "Enter elements to create BST: "<<endl;
    takeInput(root);

    cout << "Level Order Traversal of the BST:"<<endl;
    levelOrderTraversal(root);

    int node1_data, node2_data;
    cout << "Enter the data of two nodes to find their Lowest Common Ancestor: ";
    cin >> node1_data >> node2_data;

    Node* node1 = new Node(node1_data);
    Node* node2 = new Node(node2_data);

    Node* lca = LCAInBST(root, node1, node2);
    if (lca != NULL) {
        cout << "The Lowest Common Ancestor of " << node1_data << " and " << node2_data << " is: " << lca->data << endl;
    } else {
        cout << "One or both of the nodes not found in the BST.";
    }

    return 0;
}
// 10 8 21 7 27 5 4 3 -1