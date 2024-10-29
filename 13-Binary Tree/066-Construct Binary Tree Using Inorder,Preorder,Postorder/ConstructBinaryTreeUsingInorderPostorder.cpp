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

//maps node and index
void createMapping(int inorder[],map<int,int> &nodeToIndex,int size){
    for(int i=0;i<size;i++){
        nodeToIndex[inorder[i]]=i;
    }
}

Node* solve(int inorder[],int postorder[],int &postorderindex,int inorderstart,int inorderend,int size,map<int,int> &nodeToIndex){

    //when postorder pointer reaches end of postorder array or indorder start reaches end of array
    if(postorderindex<0 || inorderstart>inorderend){
        return NULL;
    }

    //making the postorder index as root node
    int element = postorder[postorderindex--];

    //node format
    Node* root = new Node(element);

    //find position of the node in inorder array
    int position=nodeToIndex[element];

    //recursively iterate the right side to make left subtree
    root->right = solve(inorder,postorder,postorderindex,position+1,inorderend,size,nodeToIndex);

    //recursively iterate the tree side to make right subtree
    root->left = solve(inorder,postorder,postorderindex,inorderstart,position-1,size,nodeToIndex);
    return root;
}

Node* constructTree(int inorder[],int postorder[],int size){

    //pointer for preorder
    int postorderindex=size-1;

    //create map for mapping between node and index
    map<int,int> nodeToIndex;
    createMapping(inorder,nodeToIndex,size);

    //inorder array,preorder array,pointer of preorder, start index of inorder, end index of inorder , size of binary tree, map nodeToIndex
    Node* ans=solve(inorder,postorder,postorderindex,0,size-1,size,nodeToIndex);
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

//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
//Inorder- Left Root Right
//Preorder- Root Left Right
//Postorder- Left Right Root