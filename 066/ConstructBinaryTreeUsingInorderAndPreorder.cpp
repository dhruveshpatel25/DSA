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

//creation of binary tree
Node* buildtree(Node *root){
    cout<<"Enter the data: "<<endl;
    int data;
    cin>>data;
    root=new Node(data);
    if(data==-1){
        return NULL;
    }

    //cout<<"Enter the data for inserting in left of "<<data<<endl;
    root->left=buildtree(root->left);
    //cout<<"Enter the data for inserting in right of "<<data<<endl;
    root->right=buildtree(root->right);
    return root;
}

void Postorder(Node* root){  //Left Node->Right Node->Root Node
    if(root==NULL){
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data<<" ";
}

int findPosition(int inorder[],int element,int size){
    for(int i=0;i<size;i++){
        if(inorder[i]==element){
            return i;
        }
    }
    return -1;
}

Node* solve(int inorder[],int preorder[],int &preorderindex,int inorderstart, int inorderend, int size){
    if(preorderindex>=size || inorderstart>inorderend){
        return NULL;
    }
    int element=preorder[preorderindex++];
    Node* root=new Node(element);
    int position=findPosition(inorder,element,size);
    root->left=solve(inorder,preorder,preorderindex,inorderstart,position-1,size);
    root->right=solve(inorder,preorder,preorderindex,position+1,inorderend,size);
    return root;
}

Node* constructTree(int inorder[],int preorder[],int size){
    int preorderindex=0;
    Node* ans=solve(inorder,preorder,preorderindex,0,size-1,size);
}

int main() {
    int size;

    cout << "Enter the number of nodes in the binary tree: ";
    cin >> size;

    int inorder[size], preorder[size];

    cout << "Enter inorder traversal: ";
    for (int i = 0; i < size; i++) {
        cin >> inorder[i];
    }

    cout << "Enter preorder traversal: ";
    for (int i = 0; i < size; i++) {
        cin >> preorder[i];
    }

    Node* root = constructTree(inorder, preorder, size);

    cout << "Binary tree constructed successfully!" << endl;
    cout<<"Postorder Traversal: ";
    Postorder(root);

    return 0;
}
