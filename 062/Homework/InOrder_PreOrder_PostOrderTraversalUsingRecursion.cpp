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

    cout<<"Enter the data for inserting in left of "<<data<<endl;
    root->left=buildtree(root->left);
    cout<<"Enter the data for inserting in right of "<<data<<endl;
    root->right=buildtree(root->right);
    return root;
}

void Inorder(Node* root){
    stack<Node*> stk;
    Node* temp=root;
    while(temp!=NULL || !stk.empty()){
        while(temp!=NULL){
            stk.push(temp);
            temp=temp->left;
        }
        temp=stk.top();
        stk.pop();
        cout<<temp->data<<" ";
        temp=temp->right;
    }
}

void Preorder(Node* root){ 
    stack<Node*> stk;
    Node* temp=root;
    
    while(temp!=NULL || !stk.empty()){
        while(temp!=NULL){
            cout<<temp->data<<" ";
            stk.push(temp);
            temp=temp->left;
        }
        temp=stk.top();
        stk.pop();
        temp=temp->right;
    }    
}

void Postorder(Node* root){
    stack<Node*> stk1;
    stack<Node*> stk2;
    Node* temp=root;
    stk1.push(temp);
    while(!stk1.empty()){
        temp=stk1.top();
        stk1.pop();
        stk2.push(temp);
        if(temp->left){
            stk1.push(temp->left);
        }
        if(temp->right){
            stk1.push(temp->right);
        }
    }

    while(!stk2.empty()){
        cout<<stk2.top()->data<<" ";
        stk2.pop();
    }
    
}

int main(){
    Node *root=NULL;
    root=buildtree(root);
    cout<<"Inorder Traversal is: ";
    Inorder(root);
    cout<<endl;
    cout<<"Preorder Traversal is: ";
    Preorder(root);
    cout<<endl;
    cout<<"Postorder Traversal is: ";
    Postorder(root);
}

//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1