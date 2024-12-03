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