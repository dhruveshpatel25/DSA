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

Node* insertToBST(Node* root,int data){
    if(root==NULL){
        root=new Node(data);
        return root;
    }

    if(data>root->data){
        root->right = insertToBST(root->right,data);
    }else{
        root->left = insertToBST(root->left,data);
    }
    return root;
}

void takeInput(Node* &root){
    int data;
    cin>>data;

    while(data!=-1){
        root=insertToBST(root,data);
        cin>>data;
    }
}

pair<int,int> predecessorAndSuccessor(Node* root,int key){
    Node* temp=root;
    int pred=-1;
    int succ=-1;
    while(temp->data!=key){
        if(temp->data>key){
            pred=temp->data;
            temp=temp->left;
        }else{
            succ=temp->data;
            temp=temp->right;
        }
    }
    Node* leftTree = temp->left;
    while(leftTree!=NULL){
        pred=leftTree->data;
        leftTree=leftTree->right;
    }

    Node* rightTree=temp->right;
    while(rightTree!=NULL){
        succ=rightTree->data;
        rightTree=rightTree->left;
    }

    pair<int,int> ans=make_pair(pred,succ);
    return ans;
}

int main() {
    Node* root = NULL;

    cout << "Enter nodes to insert into the BST: " << endl;
    takeInput(root);

    cout << "Level Order Traversal of the BST:" << endl;
    levelOrderTraversal(root);

    int key;
    cout<<"Enter the key: ";
    cin>>key;
    pair<int, int> predAndSucc = predecessorAndSuccessor(root, key);
    cout << "Predecessor and Successor of " << key << ": ";
    cout << predAndSucc.first << " " << predAndSucc.second << endl;
    return 0;
}
