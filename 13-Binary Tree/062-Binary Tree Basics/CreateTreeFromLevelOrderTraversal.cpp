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

void buildTreeFromLevelOrderTraversal(Node* &root){
    queue<Node*> que;
    cout<<"Enter the data for root: "<<endl;
    int data;
    cin>>data;
    root=new Node(data);
    que.push(root);
    while(!que.empty()){
        Node* temp=que.front();
        que.pop();

        cout<<"Enter the left node for "<<temp->data<<" ";
        int LeftData;
        cin>>LeftData;

        if(LeftData!=-1){
            temp->left=new Node(LeftData);
            que.push(temp->left);
        }

        cout<<"Enter the right node for "<<temp->data<<" ";
        int RightData;
        cin>>RightData;

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