#include<iostream>
#include<queue>
#include<stack>
#include<map>
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

void solve(Node* root,vector<int> &ans,int level){
    //base case
    if(root==NULL){
        return;
    }

    //only push the first value for that particular level
    if(level==ans.size()){
        ans.push_back(root->data);
    }

    //recursively iterate left subtree first as it is left view
    solve(root->left,ans,level+1);

    //then recursively iterate right subtree 
    solve(root->right,ans,level+1);
}

vector<int> LeftView(Node* root){
    vector<int> ans;
    solve(root,ans,0);
    return ans;
}

int main() {
    Node* root = NULL;
    root = buildtree(root);

    cout << "Left view of the binary tree: ";
    vector<int> result = LeftView(root);
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}

//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1