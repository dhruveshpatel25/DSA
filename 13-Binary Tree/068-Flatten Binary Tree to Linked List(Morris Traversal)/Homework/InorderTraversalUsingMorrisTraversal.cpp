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

        if(curr->left==NULL){
            cout<<curr->data<<" ";
            curr=curr->right;
        }else{
            Node* pred=curr->left;
            while(pred->right!=NULL && pred->right!=curr){
                pred=pred->right;
            }
            if(pred->right==NULL){
                pred->right=curr;
                curr=curr->left;
            }else{
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