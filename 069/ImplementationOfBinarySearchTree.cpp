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

void Inorder(Node* root){  //Left Node->Root Node->Right Node
    if(root==NULL){
        return;
    }

    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

void Preorder(Node* root){  //Root Node->Left Node->Right Node
    if(root==NULL){
        return;
    }
    
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}

void Postorder(Node* root){  //Left Node->Right Node->Root Node
    if(root==NULL){
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data<<" ";
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

int minival(Node* root){
    Node* temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp->data;
}

Node* deleteFromBST(Node* root,int data){
    if(root==NULL){
        return root;
    }

    if(root->data==data){
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }

        if(root->left!=NULL && root->right==NULL){
            Node* temp=root->left;
            delete root;
            return temp;
        }
        if(root->left==NULL && root->right!=NULL){
            Node* temp=root->right;
            delete root;
            return temp;
        }

        if(root->left!=NULL && root->right!=NULL){
            int mini=minival(root->right);
            root->data=mini;
            root->right=deleteFromBST(root->right,mini);
            return root;
        }
    }else if(root->data>data){
        root->left=deleteFromBST(root->left,data);
    }else{
        root->right=deleteFromBST(root->right,data);
    }

}

void takeInput(Node* &root){
    int data;
    cin>>data;

    while(data!=-1){
        root=insertToBST(root,data);
        cin>>data;
    }
}

int main() {
    Node* root = NULL;
    
    cout << "Enter elements to insert into the BST:" << endl;
    takeInput(root);

    cout << "Level Order Traversal of the BST:" << endl;
    levelOrderTraversal(root);
    cout<<endl;

    cout<< "Inorder Traversal of the BST: "<<endl;
    Inorder(root);
    cout<<endl;

    cout<< "Preorder Traversal of the BST: "<<endl;
    Preorder(root);
    cout<<endl;

    cout<< "Postorder Traversal of the BST: "<<endl;
    Postorder(root);
    cout<<endl;

    int deleteData;
    cout << "Enter the node to delete from the BST: ";
    cin >> deleteData;

    root = deleteFromBST(root, deleteData);

    cout << "Level Order Traversal of the BST:" << endl;
    levelOrderTraversal(root);
    cout<<endl;

    return 0;
}
// 10 8 21 7 27 5 4 3 -1

//Inorder in BST is sorted