/*Binary Tree from Inorder and Postorder
Given inorder and postorder traversals of a binary tree(having n nodes) in the arrays inorder[] and postorder[] respectively. The task is to construct a unique binary tree from these traversals and return its root.
Driver code will print the preorder traversal of the constructed tree.
Note: The inorder and postorder traversals contain unique values, and every value present in the postorder traversal is also found in the inorder traversal.

Examples:

Input: inorder[] = [4, 8, 2, 5, 1, 6, 3, 7], postorder[] = [8, 4, 5, 2, 6, 7, 3, 1]
Output: [1, 2, 4, 8, 5, 3, 6, 7]
Explanation: For the given postorder and inorder traversal of tree the resultant binary tree will be
          1
       /      \
     2        3
   /  \      /  \
  4   5     6    7
   \
    8

Input: inorder[] = [9, 5, 2, 3, 4], postorder[] = [5, 9, 3, 4, 2]
Output: [2, 9, 5, 4, 3]
Explanation: The resultant binary tree will be
           2
        /     \
       9      4
        \     /
         5   3
https://www.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1*/
#include<iostream>
#include<queue>
#include<stack>
#include<map>
#include<climits>
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

    //cout<<"Enter the data for inserting in left of "<<data<<endl;
    root->left=buildtree(root->left);
    //cout<<"Enter the data for inserting in right of "<<data<<endl;
    root->right=buildtree(root->right);
    return root;
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