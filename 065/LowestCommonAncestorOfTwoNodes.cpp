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

Node* lowestCommonAncestor(Node* root,int n1,int n2){
    if(root==NULL){
        return NULL;
    }

    if(root->data==n1 || root->data==n2){
        return root;
    }

    Node* leftAns=lowestCommonAncestor(root->left,n1,n2);
    Node* rightAns=lowestCommonAncestor(root->right,n1,n2);

    if(leftAns!=NULL && rightAns!=NULL){
        return root;
    }
    else if(leftAns==NULL && rightAns!=NULL){
        return rightAns;
    }
    else if(leftAns!=NULL && rightAns==NULL){
        return leftAns;
    }
    else{
        return NULL;
    }
}

int main() {
    Node* root = NULL;
    root = buildtree(root);
    int n1,n2;
    cout<<"Enter n1: ";
    cin>>n1;
    cout<<"Enter n2: ";
    cin>>n2;
    Node* lca = lowestCommonAncestor(root, n1, n2);
    if (lca != NULL) {
        cout << "Lowest Common Ancestor of " << n1 << " and " << n2 << " is: " << lca->data << endl;
    } else {
        cout << "Lowest Common Ancestor of " << n1 << " and " << n2 << " doesn't exist!" << endl;
    }

    return 0;
}
//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1