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

//level order traversal-printing in tree form
void levelOrderTraversal(Node *root){
    queue<Node*> que;
    que.push(root);

    //separator-used to separate 2 levels in tree
    que.push(NULL);

    while(!que.empty()){
        Node* temp=que.front();
        que.pop();

        //last level is complete
        if(temp==NULL){
            cout<<endl;

            //queue still has child nodes
            if(!que.empty()){
                que.push(NULL);
            }
        }
        else
        { 
            cout<<temp->data<<" ";

            //pushing the left child
            if(temp->left){
                que.push(temp->left);
            }

            //pushing the right child
            if(temp->right){
                que.push(temp->right);
            }
        }
    }
}

bool isValidate(Node* root,int mini,int maxi){
    if(root==NULL){
        return true;
    }

    if(root->data>=mini && root->data<=maxi){

        //recursivly check for left subtree
        bool left=isValidate(root->left,mini,root->data);

        //recursivly check for right subtree
        bool right=isValidate(root->right,root->data,maxi);

        //if both are true
        return left && right;
    }
    else{
        return false;
    }
}

bool validateBST(Node* root){
    return isValidate(root,INT_MIN,INT_MAX);
}

int main() {
    Node* root = NULL;
    
    cout << "Enter nodes to insert into the BST: " << endl;
    root=buildtree(root);

    cout << "Level Order Traversal of the BST:" << endl;
    levelOrderTraversal(root);

    if (validateBST(root)) {
        cout << "The binary tree is a valid BST." << endl;
    } else {
        cout << "The binary tree is not a valid BST." << endl;
    }

    return 0;
}
// 10 8 21 7 27 5 4 3 -1