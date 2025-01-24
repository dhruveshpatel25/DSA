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

void buildTreeFromLevelOrderTraversal(Node* &root){
    queue<Node*> que;

    //take data
    cout<<"Enter the data for root: "<<endl;
    int data;
    cin>>data;

    //make it root
    root=new Node(data);
    que.push(root);
    while(!que.empty()){
        Node* temp=que.front();
        que.pop();

        //left node
        cout<<"Enter the left node for "<<temp->data<<" ";
        int LeftData;
        cin>>LeftData;

        //if not NULL push
        if(LeftData!=-1){
            temp->left=new Node(LeftData);
            que.push(temp->left);
        }

        //right node
        cout<<"Enter the right node for "<<temp->data<<" ";
        int RightData;
        cin>>RightData;

        //if not NULL push
        if(RightData!=-1){
            temp->right = new Node(RightData);
            que.push(temp->right);
        }
    }
}

int main(){
    Node* root=NULL;
    buildTreeFromLevelOrderTraversal(root);
    levelOrderTraversal(root);
}
//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1