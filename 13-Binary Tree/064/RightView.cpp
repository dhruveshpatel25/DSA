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
    if(root==NULL){
        return;
    }

    if(level==ans.size()){
        ans.push_back(root->data);
    }

    solve(root->right,ans,level+1);
    solve(root->left,ans,level+1);
}

vector<int> rightView(Node* root){
    vector<int> ans;
    solve(root,ans,0);
    return ans;
}

int main() {
    Node* root = NULL;
    root = buildtree(root);

    cout << "Right view of the binary tree: ";
    vector<int> result = rightView(root);
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}