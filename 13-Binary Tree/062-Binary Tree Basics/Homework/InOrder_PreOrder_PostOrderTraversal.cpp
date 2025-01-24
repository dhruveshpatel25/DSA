#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class Node{
    public:
    int data;

    //left subtree
    Node *left;

    //right subtree
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

    //recursively calling left side of tree till it reaches NULL
    cout<<"Enter the data for inserting in left of "<<data<<endl;
    root->left=buildtree(root->left);

    //recursively calling right of tree till it reaches NULL
    cout<<"Enter the data for inserting in right of "<<data<<endl;
    root->right=buildtree(root->right);
    return root;
}

//Left Node->Root Node->Right Node
void Inorder(Node* root){
    stack<Node*> stk;
    Node* temp=root;
    while(temp!=NULL || !stk.empty()){
        while(temp!=NULL){

            //push the root node
            stk.push(temp);

            //iterate left subtree
            temp=temp->left;
        }
        temp=stk.top();
        stk.pop();

        //print the current node
        cout<<temp->data<<" ";

        //iterate the right subtree
        temp=temp->right;
    }
}

//Root Node->Left Node->Right Node
void Preorder(Node* root){ 
    stack<Node*> stk;
    Node* temp=root;
    
    while(temp!=NULL || !stk.empty()){
        while(temp!=NULL){

            //print the root node first
            cout<<temp->data<<" ";
            stk.push(temp);

            //iterate the left subtree
            temp=temp->left;
        }
        temp=stk.top();
        stk.pop();

        //iterate the right subtree
        temp=temp->right;
    }    
}

//Left Node->Right Node->Root Node
void Postorder(Node* root){
    stack<Node*> stk1;
    stack<Node*> stk2;
    Node* temp=root;

    //push the root node
    stk1.push(temp);
    while(!stk1.empty()){

        //remove the top element
        temp=stk1.top();
        stk1.pop();

        //push in 2nd stack
        stk2.push(temp);

        //push the left child node
        if(temp->left){
            stk1.push(temp->left);
        }

        //push the right child node
        if(temp->right){
            stk1.push(temp->right);
        }
    }

    //print the 2nd stack
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