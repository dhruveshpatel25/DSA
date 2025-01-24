/*Find K-th smallest Element in BST
Problem statement
Given a binary search tree and an integer ‘K’. Your task is to find the ‘K-th’ smallest element in the given BST( binary search tree).

BST ( binary search tree) -
If all the smallest nodes on the left side and all the greater nodes on the right side of the node current node.

Example -
Order of elements in increasing order in the given BST is - { 2, 3, 4, 5, 6, 7, 8, 10 }
Suppose given ‘K = 3’ then 3rd smallest element is ‘4’.
Suppose given ‘K = 8’ then 8th smallest element is ‘10’.

Note:
1. You are not required to print the output explicitly, it has already been taken care of. Just implement the function and return the ‘K-th’ smallest element of BST.
2. You don’t need to return ‘K-th’ smallest node, return just value of that node. 
3. If ‘K-th’ smallest element is not present in BST then return -1.
https://www.naukri.com/code360/problems/find-k-th-smallest-element-in-bst_1069333*/
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

int solve(Node* root,int &i,int k){
    if(root==NULL){
        return -1;
    }

    //check for largest value
    int right=solve(root->right,i,k);

    //if it exist return the value
    if(right!=-1){
        return right;
    }

    //increase the count
    i++;

    //check the count with k
    if(i==k){
        return root->data;
    }

    //if not right then left
    return solve(root->left,i,k);
}

int kthLargest(Node* root,int i,int k){
    i=0;
    int ans=solve(root,i,k);
    return ans;
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

int main() {
    Node* root = NULL;
    
    cout << "Enter elements to insert into the BST: " << endl;
    takeInput(root);

    cout << "Level Order Traversal of the BST:" << endl;
    levelOrderTraversal(root);

    int k;
    cout << "Enter the value of k to find the kth largest element: ";
    cin >> k;

    int kthLargestElement = kthLargest(root, 0, k);
    cout << "The " << k << "th largest element in the BST is: " << kthLargestElement << endl;

    return 0;
}
// 10 8 21 7 27 5 4 3 -1