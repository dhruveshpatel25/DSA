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

    //base case
    if(root==NULL){
        return NULL;
    }

    //checking if current node is n1 or n2
    if(root->data==n1 || root->data==n2){
        return root;
    }

    //recursively iterate left subtree
    Node* leftAns=lowestCommonAncestor(root->left,n1,n2);

    //recursively iterate right subtree
    Node* rightAns=lowestCommonAncestor(root->right,n1,n2);

    //if both the side has n1 and n2 then return the root as lowest common ancestor
    if(leftAns!=NULL && rightAns!=NULL){
        return root;
    }

    //if only the right subtree has n1 or n2 then return the value above
    else if(leftAns==NULL && rightAns!=NULL){
        return rightAns;
    }

    //if only the left subtree has n1 or n2 then return the value above
    else if(leftAns!=NULL && rightAns==NULL){
        return leftAns;
    }

    //if both side dont have n1 or n2 then return NULL
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