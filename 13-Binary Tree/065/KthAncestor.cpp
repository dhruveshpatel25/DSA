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

Node* solve(Node* root,int &k,int node){
    if(root==NULL){
        return NULL;
    }
    if(root->data==node){
        return root;
    }
    Node* leftAns=solve(root->left,k,node); 
    Node* rightAns=solve(root->right,k,node);
    if(leftAns!=NULL && rightAns==NULL){
        k--;
        if(k<=0){
            k=INT_MAX;
            return root;
        }
        return leftAns;
    }

    if(leftAns==NULL && rightAns!=NULL){
        k--;
        if(k<=0){
            k=INT_MAX;
            return root;
        }
        return rightAns;
    }

    return NULL;
}

int kAncestor(Node* root,int k,int node){
    Node* ans=solve(root,k,node);
    if(ans==NULL || ans->data==node){
        return false;
    }else{
        return root->data;
    }
}

int main() {
    Node *root = NULL;
    root = buildtree(root);

    int k, node;
    cout << "Enter the node value: ";
    cin >> node;
    cout << "Enter the value of k: ";
    cin >> k;

    int ancestor = kAncestor(root, k, node);
    if (ancestor)
        cout << "The kth ancestor of node " << node << " is: " << ancestor << endl;
    else
        cout << "No kth ancestor found for node " << node << endl;

    return 0;
}
//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1