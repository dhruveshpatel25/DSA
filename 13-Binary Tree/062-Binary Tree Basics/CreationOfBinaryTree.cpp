#include<iostream>
#include<queue>
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

int main(){
    Node *root=NULL;
    root=buildtree(root);
    levelOrderTraversal(root);
}

//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1