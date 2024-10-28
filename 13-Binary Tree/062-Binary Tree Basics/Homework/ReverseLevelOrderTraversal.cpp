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


void reverselevelOrderTraversal(Node *root){
    stack<Node*> stk;
    queue<Node*> que;
    que.push(root);
    que.push(NULL);

    while(!que.empty()){
        Node* temp=que.front();
        que.pop();
        stk.push(temp);

        if(temp==NULL){ 
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

    cout<<"Hi";
    while(!stk.empty()){
        Node* temp=stk.top();
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