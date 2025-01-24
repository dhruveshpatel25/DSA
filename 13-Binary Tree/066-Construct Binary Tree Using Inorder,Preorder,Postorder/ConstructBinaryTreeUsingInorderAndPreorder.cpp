/*Construct Tree from Inorder & Preorder
Given two arrays representing the inorder and preorder traversals of a binary tree, construct the tree and return the root node of the constructed tree.
Note: The output is written in postorder traversal.

Examples:

Input: inorder[] = [1, 6, 8, 7], preorder[] = [1, 6, 7, 8]
Output: [8, 7, 6, 1]
Explanation: The tree will look like
       1 
          \  
            6
               \
                 7
              /
           8

Input: inorder[] = [3, 1, 4, 0, 5, 2], preorder[] = [0, 1, 3, 4, 2, 5]
Output: [3, 4, 1, 5, 2, 0]
Explanation: The tree will look like
       0
    /     \
   1       2
 /   \    /
3    4   5

Input: inorder[] = [2, 5, 4, 1, 3], preorder[] = [1, 4, 5, 2, 3]
Output: [2, 5, 4, 3, 1]
Explanation: The tree will look like
        1
     /     \
    4       3
   /
  5
 /
2
https://www.geeksforgeeks.org/problems/construct-tree-1/1*/
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

void Postorder(Node* root){  //Left Node->Right Node->Root Node
    if(root==NULL){
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data<<" ";
}

//maps node and index
void createMapping(int inorder[],map<int,int> &nodeToIndex,int size){
    for(int i=0;i<size;i++){
        nodeToIndex[inorder[i]]=i;
    }
}

Node* solve(int inorder[],int preorder[],int &preorderindex,int inorderstart, int inorderend, int size,map<int,int> &nodeToIndex){

    //when preorder pointer reaches end of preorder array or indorder start reaches end of array
    if(preorderindex>=size || inorderstart>inorderend){
        return NULL;
    }

    //making the preorder index as root node
    int element=preorder[preorderindex++];

    //node format
    Node* root=new Node(element);

    //find position of the node in inorder array
    int position=nodeToIndex[element];

    //recursively iterate the left side to make left subtree
    root->left=solve(inorder,preorder,preorderindex,inorderstart,position-1,size,nodeToIndex);

    //recursively iterate the right side to make right subtree
    root->right=solve(inorder,preorder,preorderindex,position+1,inorderend,size,nodeToIndex);
    return root;
}

Node* constructTree(int inorder[],int preorder[],int size){

    //pointer for preorder
    int preorderindex=0;

    //create map for mapping between node and index
    map<int,int> nodeToIndex;
    createMapping(inorder,nodeToIndex,size);

    //inorder array,preorder array,pointer of preorder, start index of inorder, end index of inorder , size of binary tree
    Node* ans=solve(inorder,preorder,preorderindex,0,size-1,size,nodeToIndex); 

    return ans;
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

//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
//Inorder- Left Root Right
//Preorder- Root Left Right
//Postorder- Left Right Root
