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

void Preorder(Node* root){  //Root Node->Left Node->Right Node
    if(root==NULL){
        return;
    }
    
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}

int findPosition(int inorder[],int element,int size){
    for(int i=0;i<size;i++){
        if(inorder[i]==element){
            return i;
        }
    }
    return -1;
}

Node* solve(int inorder[],int postorder[],int &postorderindex,int inorderstart,int inorderend,int size){
    if(postorderindex<0 || inorderstart>inorderend){
        return NULL;
    }
    int element = postorder[postorderindex--];
    Node* root = new Node(element);
    int position=findPosition(inorder,element,size);
    root->right = solve(inorder,postorder,postorderindex,position+1,inorderend,size);
    root->left = solve(inorder,postorder,postorderindex,inorderstart,position-1,size);
    return root;
}

Node* constructTree(int inorder[],int postorder[],int size){
    int postorderindex=size-1;
    Node* ans=solve(inorder,postorder,postorderindex,0,size-1,size);
    return ans;
}

int main() {
    int size;

    cout << "Enter the number of nodes in the binary tree: ";
    cin >> size;

    int inorder[size], postorder[size];

    cout << "Enter inorder traversal: ";
    for (int i = 0; i < size; i++) {
        cin >> inorder[i];
    }

    cout << "Enter postorder traversal: ";
    for (int i = 0; i < size; i++) {
        cin >> postorder[i];
    }

    Node* root = constructTree(inorder, postorder, size);

    cout << "Binary tree constructed successfully!" << endl;
    cout<<"Preorder traversal: ";
    Preorder(root);

    return 0;
}