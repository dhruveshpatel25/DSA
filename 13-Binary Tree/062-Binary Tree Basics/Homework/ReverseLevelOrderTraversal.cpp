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

//building the tree
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

//traversing the tree in reverse order
void reverselevelOrderTraversal(Node *root){
    stack<Node*> stk;
    queue<Node*> que;
    que.push(root);

    //separator-used to separate 2 levels in tree
    que.push(NULL);

    while(!que.empty()){
        Node* temp=que.front();
        que.pop();
        stk.push(temp);

        //last level is complete
        if(temp==NULL){ 

            //queue still has child nodes
            if(!que.empty()){
                que.push(NULL);
            }
        }
        else
        { 
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

    //iterating the stack till its empty
    while(!stk.empty()){
        Node* temp=stk.top();

        //checking if the temp value is NULL or element
        if(temp==NULL){
            cout<<endl;
        }else{
            cout<<temp->data<<" ";
        }
        stk.pop();
    }
}

int main(){
    Node *root=NULL;
    root=buildtree(root);
    reverselevelOrderTraversal(root);
}

//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1