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
    que.push(NULL);

    while(!que.empty()){
        Node* temp=que.front();
        que.pop();

        if(temp==NULL){ //last level is complete
            cout<<endl;
            if(!que.empty()){
                que.push(NULL);
            }
        }
        else
        { 
            cout<<temp->data<<" ";
            if(temp->left){
                que.push(temp->left);
            }

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
        bool left=isValidate(root->left,mini,root->data);
        bool right=isValidate(root->right,root->data,maxi);
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
