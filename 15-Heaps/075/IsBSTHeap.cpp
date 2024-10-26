#include<iostream>
#include<queue>
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

int countnodes(Node* root){
    if(root==NULL){
        return 0;
    }
    int ans=1+countnodes(root->left)+countnodes(root->right);
    return ans;
}

bool isCBT(Node* root,int index,int totalcount){
    if(root==NULL){
        return true;
    }
    if(index>=totalcount){
        return false;
    }else{
        bool left=isCBT(root->left,2*index+1,totalcount);
        bool right=isCBT(root->right,2*index+2,totalcount);
        return(left&&right);
    }
}

bool isMaxOrder(Node* root){
    if(root->left==NULL && root->right==NULL){
        return true;
    }
    if(root->right==NULL){
        return(root->data>root->left->data);
    }else{
        bool left= isMaxOrder(root->left);
        bool right= isMaxOrder(root->right);
        if(left && right && (root->data>root->left->data && root->data>root->right->data)){
            return true;
        }else{
            return false;
        }
    }
}

bool isHeap(Node* root){
    int index=0;
    int totalcount=countnodes(root);
    if(isCBT(root,index,totalcount) && isMaxOrder(root)){
        return true;
    }
}

int main() {
    Node *root = NULL;
    root = buildtree(root);

    // Check if the tree is a max heap
    if (isHeap(root)) {
        cout << "The binary tree is a max heap." << endl;
    } else {
        cout << "The binary tree is not a max heap." << endl;
    }

    return 0;
}
