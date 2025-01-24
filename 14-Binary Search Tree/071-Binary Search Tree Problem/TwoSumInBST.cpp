/*Two Sum IV - Input is a BST
You have been given a Binary Search Tree and a target value. You need to find out whether there exists a pair of node values in the BST, such that their sum is equal to the target value.

A binary search tree (BST), also called an ordered or sorted binary tree, is a rooted binary tree whose internal nodes each store a value greater than all the values keys in the node's left subtree and less than those in its right subtree.
https://www.naukri.com/code360/problems/two-sum-in-a-bst_1062631*/
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
    }else{ 
        
    //iterate to left if the data is smaller than the root data
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
//Left Node->Root Node->Right Node
void Inorder(Node* root,vector<int> &inorderval){ 
    if(root==NULL){
        return;
    }

    Inorder(root->left,inorderval);
    inorderval.push_back(root->data);
    Inorder(root->right,inorderval);
}

bool twoSumInBST(Node* root,int target){
    vector<int> inorderval;

    //convert BST to inorder traversal
    Inorder(root,inorderval);
    int i=0;
    int j=inorderval.size()-1;

    while(i<j){
        int sum=inorderval[i]+inorderval[j];

        //if sum = target
        if(sum==target){
            return true;

        //if sum is greater than target
        }else if(sum>target){
            j--;
        }else{ //if sum is smaller than target
            i++;
        }
    }
    return false;
}

int main() {
    Node* root = NULL;
    cout << "Enter elements to insert into BST: ";
    takeInput(root);

    cout << "Level Order Traversal of BST: " << endl;
    levelOrderTraversal(root);

    int target;
    cout << "Enter the target sum: ";
    cin >> target;

    if (twoSumInBST(root, target)) {
        cout << "There exist two elements in the BST that sum up to " << target << "." << endl;
    } else {
        cout << "No two elements in the BST sum up to " << target << "." << endl;
    }

    return 0;
}
// 10 8 21 7 27 5 4 3 -1