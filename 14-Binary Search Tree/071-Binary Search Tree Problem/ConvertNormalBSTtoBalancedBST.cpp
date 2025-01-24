/*Normal BST To Balanced BST
You have been given a binary search tree of integers with ‘N’ nodes. Your task is to convert it into a balanced BST with the minimum height possible.

A binary search tree (BST) is a binary tree data structure that has the following properties.

• The left subtree of a node contains only nodes with data less than the node’s data.
• The right subtree of a node contains only nodes with data greater than the node’s data.
• Both the left and right subtrees must also be binary search trees.
A Balanced BST is defined as a BST, in which the height of two subtrees of every node differs no more than 1.
https://www.naukri.com/code360/problems/normal-bst-to-balanced-bst_920472*/
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

Node* buildtree(Node *root){
    cout<<"Enter the data: "<<endl;
    int data;
    cin>>data;
    root=new Node(data);
    if(data==-1){
        return NULL;
    }

    cout<<"Enter the data for inserting in left of "<<data<<endl;
    root->left=buildtree(root->left);
    cout<<"Enter the data for inserting in right of "<<data<<endl;
    root->right=buildtree(root->right);
    return root;
}

//level order traversal-printing in tree form
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
void Inorder(Node* root,vector<int> &inorderval){  
    if(root==NULL){
        return;
    }

    Inorder(root->left,inorderval);
    inorderval.push_back(root->data);
    Inorder(root->right,inorderval);
}

Node* convertToBalancedBST(int start,int end,vector<int> &inorderval){
    if(start>end){
        return NULL;
    }

    int mid=(start+end)/2;

    //take the mid value as root 
    Node* newroot=new Node(inorderval[mid]);

    //recursivly iterate to the left subtree for smaller value
    newroot->left=convertToBalancedBST(start,mid-1,inorderval);

    //recursivly iterate to the right subtree for biggervalue
    newroot->right=convertToBalancedBST(mid+1,end,inorderval);
    return newroot;
}

Node* balancedBST(Node* root){
    vector<int> inorderval;

    //convert normal tree to inorder
    Inorder(root,inorderval);
    return convertToBalancedBST(0,inorderval.size()-1,inorderval);
}

int main() {
    Node* root = NULL;

    cout << "Enter elements to insert into the BST (-1 to stop):" << endl;
    root=buildtree(root);

    cout << "Original BST (Level Order Traversal):" << endl;
    levelOrderTraversal(root);

    root = balancedBST(root);

    cout << "Balanced BST (Level Order Traversal):" << endl;
    levelOrderTraversal(root);

    return 0;
}
// 10 8 21 7 27 5 4 3 -1