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

void Inorder(Node* root){  //Left Node->Root Node->Right Node
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