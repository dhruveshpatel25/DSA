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

/*bool checkBalance(Node* root){
    if(root==NULL){
        return true;
    }

    //recursively iterates left subtree
    bool left = checkBalance(root->left);

    //recursively iterates right subtree
    bool right = checkBalance(root->right);

    //checks the balance of current node
    bool diff = height(root->left)-height(root->right)<=1;

    //checks the condition whether the right,left & current node are balanced or not
    if(left && right && diff){
        return true;
    }else{
        return false;
    }
    return ans;
}*/

pair<bool,int> checkBalance(Node* root){
    if(root==NULL){
        pair<bool,int> p=make_pair(true,0);
        return p;
    }

    //recursively iterates left subtree
    pair<bool,int> left= checkBalance(root->left);

    //recursively iterates right subtree
    pair<bool,int> right= checkBalance(root->right);

    //contains the balanced condition of left subtree
    bool leftAns=left.first;

    //contains the balanced condition of right subtree
    bool rightAns=right.first;

    //checks the balance of current node
    bool difference=abs(left.second-right.second)<=1;

    pair<bool,int>ans;

    //finds the maximum height of current node
    ans.second=max(left.second,right.second)+1;

    //checks the condition whether the right,left & current node are balanced or not
    if(leftAns&&rightAns&&difference){
        ans.first=true;
    }else{
        ans.first=false;
    } 
    return ans;
}

bool isBalanced(Node* root){
    return checkBalance(root).first;
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
