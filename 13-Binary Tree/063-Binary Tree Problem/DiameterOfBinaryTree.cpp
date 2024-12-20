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

pair<int,int> Diameter(Node* root){
    if(root==NULL){
        pair<int,int> p= make_pair(0,0);
        return p;
    }

    pair<int,int> left = Diameter(root->left);
    pair<int,int> right = Diameter(root->right);

    int op1=left.first; //diameter of left subtree
    int op2=right.first; //diameter of right subtree
    int op3=left.second+right.second+1; //diameter passing through current node    

    pair<int,int> ans;
    ans.first= max(op1,max(op2,op3)); //diameter of current node
    ans.second=max(left.first,right.second)+1; //height of the current node
    return ans;
}

int diameter(Node* root){
    return Diameter(root).first;
}

int main() {
    Node* root = NULL;
    root = buildtree(root);
    int result = diameter(root);
    cout << "Diameter of the tree is: " << result<< endl;

    return 0;
}

//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1