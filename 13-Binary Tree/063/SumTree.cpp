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

pair<bool,int> sumTree(Node* root){
    if(root==NULL){
        pair<bool,int> p = make_pair(true,0);
        return p;
    }

    if(root->left==NULL && root->right==NULL){
        pair<bool,int> p = make_pair(false,root->data);
        return p;
    }

    pair<bool,int> left= sumTree(root->left);
    pair<bool,int> right= sumTree(root->right);

    bool leftAns=left.first;
    bool rightAns=right.first;
    bool codn= root->data == left.second+right.second;
    pair<bool,int> ans;
    if(leftAns&&rightAns&&codn){
        ans.first=true;
        ans.second=2*root->data;
    }else{
        ans.first=false;
    }
    return ans;
}

int main() {
    Node *root = NULL;
    root = buildtree(root);

    pair<bool, int> result = sumTree(root);

    if (result.first) {
        cout << "The binary tree is a sum tree." << endl;
    } else {
        cout << "The binary tree is not a sum tree." << endl;
    }

    return 0;
}
