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

bool solve(Node* root, int k, vector<int>& ancestor, int node){
    if(root==NULL){
        return false;
    }
    ancestor.push_back(root->data);
    if(root->data == node || solve(root->left, k, ancestor, node) || solve(root->right, k, ancestor, node)){
        return true;
    }
    ancestor.pop_back();
    return false;
}

void kAncestor(Node* root, int k, int node){
    vector<int> ancestor;
    if(solve(root, k, ancestor, node)){
        if(k <= ancestor.size()){
            cout << k << "-th ancestor of node " << node << " is: " << ancestor[ancestor.size() - (k+1)] << endl;
        } else {
            cout << "No such ancestor exists." << endl;
        }
    } else {
        cout << "Node " << node << " not found in the tree." << endl;
    }
}

int main() {
    Node *root=NULL;
    root=buildtree(root);
    int k, node;
    cout<<"Enter the node value: ";
    cin>>node;
    cout<<"Enter the value of k: ";
    cin>>k;
    kAncestor(root, k, node);
}