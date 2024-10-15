#include<iostream>
#include<queue>
#include<stack>
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

void TraversalLeft(Node* root, vector<int> &ans){
    if((root==NULL)||(root->left==NULL && root->right==NULL)){
        return;
    }
    ans.push_back(root->data);
    if(root->left){
        TraversalLeft(root->left,ans);
    }else{
        TraversalLeft(root->right,ans);
    }
}

void TraversalLeaf(Node* root,vector<int> &ans){
    if(root==NULL){
        return;
    }

    if(root->left==NULL && root->right==NULL){
        ans.push_back(root->data);
        return;
    }

    TraversalLeaf(root->left,ans);
    TraversalLeaf(root->right,ans);
}

void TraversalRight(Node* root,vector<int> &ans){
    if((root==NULL)||(root->left==NULL && root->right==NULL)){
        return;
    }
    if(root->right){
        TraversalRight(root->right,ans);
    }else{
        TraversalRight(root->left,ans);
    }
    ans.push_back(root->data);
}

vector<int> boundaryTraversal(Node* root){
    vector<int> ans;
    if(root==NULL){
        return ans;
    }
    ans.push_back(root->data);

    TraversalLeft(root->left,ans);
    TraversalLeaf(root->left,ans);
    TraversalLeaf(root->right,ans);
    TraversalRight(root->right,ans);

    return ans;
}

int main() {
    Node *root = NULL;
    root = buildtree(root);

    cout << "Boundary Traversal of the binary tree:" << endl;
    vector<int> result = boundaryTraversal(root);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
