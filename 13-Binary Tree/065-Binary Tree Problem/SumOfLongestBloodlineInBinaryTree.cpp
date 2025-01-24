/*Sum of nodes on the longest path
Given a binary tree root, you need to find the sum of the nodes on the longest path from the root to any leaf node. If two or more paths have the same length, the path with the maximum sum of node values should be considered.

Examples:

Input: root[] = [4, 2, 5, 7, 1, 1, 2, 3, N, 6]
Output: 13
Explanation:
The highlighted nodes (4, 2, 1, 6) above are part of the longest root to leaf path having sum = (4 + 2 + 1 + 6) = 13

Input: root[] = [1, 2, 3, 4, 5, 6, 7]
          1
        /   \
       2     3
      / \   / \
     4   5 6   7
Output: 11
Explanation: Use path 1->3->7, with sum 11.

Input: root[] = [10, 5, 15, 3, 7, N, 20, 1]
          10
        /    \
       5      15
      / \       \
     3   7       20
    /
   1
Output: 19
Explanation: The longest root-to-leaf path is 10 -> 5 -> 3 -> 1 with a sum of 10 + 5 + 3 + 1 = 19.
https://www.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1*/
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

void solve(Node* root,int len,int& Maxlen,int sum,int& Maxsum){

    //crossed the leaf node
    if(root==NULL){

        //if the length of particular node is greater than the previous maximum
        if(len>Maxlen){
            Maxlen=len;
            Maxsum=sum;
        }

        //if it is same then calculate the maximum sum
        else if(len==Maxlen){
            Maxsum=max(sum,Maxsum);
        }
        return;
    }

    //calculate the sum for each node during traversal
    sum=sum+root->data;

    //recursively iterating left subtree by increasing length by 1
    solve(root->left,len+1,Maxlen,sum,Maxsum);

    //recursively iterating right subtree by increasing length by 1
    solve(root->right,len+1,Maxlen,sum,Maxsum);
}

int sumOfLongRootToLeafPath(Node* root){
    //calculating the length of traversal
    int len=0;

    //storing the maximum length
    int Maxlen=0;

    //calulating sum of traversal
    int sum=0;

    //storing the maximum sum
    int Maxsum=INT_MIN;
    solve(root,len,Maxlen,sum,Maxsum);
    return Maxsum;
}

int main() {
    Node* root = NULL;
    root = buildtree(root);

    int maxSum = sumOfLongRootToLeafPath(root);
    cout << "Maximum sum of nodes in the longest path from root to leaf: " << maxSum << endl;

    return 0;
}
//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1