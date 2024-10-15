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
int height(Node* root){
    if(root==NULL){
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    int ans= max(left,right)+1;
    return ans;
}

bool checkBalance(Node* root){
    if(root==NULL){
        return true;
    }

    bool left = checkBalance(root->left);
    bool right = checkBalance(root->right);
    bool diff = height(root->left)-height(root->right)<=1;

    if(left && right && diff){
        return true;
    }else{
        return false;
    }
}

/*pair<bool,int> checkBalance(Node* root){
    if(root==NULL){
        pair<bool,int> p=make_pair(true,0);
        return p;
    }

    pair<bool,int> left= checkBalance(root->left);
    pair<bool,int> right= checkBalance(root->right);

    bool leftAns=left.first;
    bool rightAns=right.first;

    bool diff=abs(left.second-right.second)<=1;
    pair<bool,int>ans;
    ans.second=max(left.second,right.second)+1;

    if(leftAns&&rightAns&&diff){
        ans.first=true;
    }else{
        ans.first=false;
    } 
}*/

bool isBalanced(Node* root){
    return checkBalance(root);
}

int main() {
    Node* root = NULL;
    root=buildtree(root);
    if (isBalanced(root)) {
        cout << "The binary tree is balanced." << endl;
    } else {
        cout << "The binary tree is not balanced." << endl;
    }

    return 0;
}


//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
