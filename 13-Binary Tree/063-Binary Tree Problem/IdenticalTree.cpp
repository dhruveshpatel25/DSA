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

bool isIdentical(Node* root1,Node* root2){
    if(root1==NULL && root2==NULL){
        return true;
    }

    if(root1==NULL && root2!=NULL){
        return false;
    }

    if(root1!=NULL && root2==NULL){
        return false;
    }

    //recursilvely iterates left subtree
    bool left=isIdentical(root1->left,root2->left);

    //recursilvely iterates right subtree
    bool right=isIdentical(root1->right,root2->right);

    //checks if the data in the node are same or not
    bool val=root1->data==root2->data;

    //checks if the data on both the tree are same or not
    if(left&&right&&val){
        return true;
    }else{
        return false;
    }
}

int main() {
    Node* root1 = NULL;
    Node* root2 = NULL;
    root1 = buildtree(root1);
    root2 = buildtree(root2);

    if (isIdentical(root1, root2)) {
        cout << "The two binary trees are identical." << endl;
    } else {
        cout << "The two binary trees are not identical." << endl;
    }
    return 0;
}

//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1