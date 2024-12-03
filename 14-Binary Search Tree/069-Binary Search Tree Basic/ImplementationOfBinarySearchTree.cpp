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

//Left Node->Root Node->Right Node
void Inorder(Node* root){  
    if(root==NULL){
        return;
    }

    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

//Root Node->Left Node->Right Node
void Preorder(Node* root){  
    if(root==NULL){
        return;
    }
    
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}

//Left Node->Right Node->Root Node
void Postorder(Node* root){  
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

    //iterate to right if the data is greater than the root data
    if(data>root->data){
        root->right = insertToBST(root->right,data);
    }else{ //iterate to left if the data is smaller than the root data
        root->left = insertToBST(root->left,data);
    }
    return root;
}

int minival(Node* root){
    Node* temp=root;

    //check till the smallest value
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp->data;
}

Node* deleteFromBST(Node* root,int data){
    if(root==NULL){
        return root;
    }

    //if you find the data to be deleted
    if(root->data==data){

        //if it does not have any child node
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }

        //if it has left child
        if(root->left!=NULL && root->right==NULL){
            Node* temp=root->left;
            delete root;
            return temp;
        }

        //if it has right child
        if(root->left==NULL && root->right!=NULL){
            Node* temp=root->right;
            delete root;
            return temp;
        }

        //if it has both the child
        if(root->left!=NULL && root->right!=NULL){

            //find the minimum in the right subtree
            int mini=minival(root->right);
            root->data=mini;
            root->right=deleteFromBST(root->right,mini);
            return root;
        }

    //if the value is smaller than the root
    }else if(root->data>data){
        root->left=deleteFromBST(root->left,data);
    }else{ //if the value is greater than the root
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