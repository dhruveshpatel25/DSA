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

Node* insertToBST(Node* root,int data){
    if(root==NULL){
        root=new Node(data);
        return root;
    }

    //iterate to right if the data is greater than the root data
    if(data>root->data){
        root->right = insertToBST(root->right,data);
    }else{ //iterate to left if the data is smaller than the root data
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

    //iterate till we kind the key
    while(temp->data!=key){

        //iterate left till we find the key
        if(temp->data>key){

            //while iterating save the value of successor
            succ=temp->data;
            temp=temp->left;
        }else{ //iterate right if the key is greater than root->data

            //while iterating save the value of predecessor
            pred=temp->data;
            temp=temp->right;
        }
    }

    Node* leftTree = temp->left;

    //check if there could be possible right subtree to for predecessor
    while(leftTree!=NULL){
        pred=leftTree->data;
        leftTree=leftTree->right;
    }

    Node* rightTree=temp->right;

    //check if there could be possible left subtree to for successor
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
// 10 8 21 7 27 5 4 3 -1