/*ZigZag Tree Traversal
Given a binary tree with n nodes. Find the zig-zag level order traversal of the binary tree.
In zig zag traversal starting from the first level go from left to right for odd-numbered levels and right to left for even-numbered levels.

Examples:

Input:
        1
      /   \
     2      3
    / \    /  \
   4   5  6    7
Output: [1, 3, 2, 4, 5, 6, 7]
Explanation:
For level 1 going left to right, we get traversal as {1}.
For level 2 going right to left, we get traversal as {3,2}.
For level 3 going left to right, we get traversal as {4,5,6,7}.
Merging all this traversals in single array we get {1,3,2,4,5,6,7}.

Input:
          7
        /   \
       9     7
     /  \   /   
    8   8  6     
   /  \
  10   9 
Output: [7, 7, 9, 8, 8, 6, 9, 10] 
Explanation:
For level 1 going left to right, we get traversal as {7}.
For level 2 going right to left, we get traversal as {7,9}.
For level 3 going left to right, we get traversal as {8,8,6}.
For level 4 going right to left, we get traversal as {9,10}.
Merging all this traversals in single array we get {7,7,9,8,8,6,9,10}.

Input:
          5
        /   \
       1     9
      / \   / \
     3   2 8   4

Output: [5, 9, 1, 3, 2, 8, 4]
Explanation:
For level 1 going left to right, we get traversal as {5}.
For level 2 going right to left, we get traversal as {9,1}.
For level 3 going left to right, we get traversal as {3,2,8,4}.
Merging all this traversals in single array we get {5,9,1,3,2,8,4}.
https://www.geeksforgeeks.org/problems/zigzag-tree-traversal/1*/
#include<iostream>
#include<queue>
#include<stack>
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

vector<int> zigzagTraversal(Node* root){
    vector<int> result;
    if(root==NULL){
        return result;
    }
    queue<Node*> que;
    que.push(root);

    //creating flag
    bool LeftToRight=true;
    while(!que.empty()){
        int size=que.size();
        vector<int> ans(size);
        for(int i=0;i<size;i++){

            //process level
            Node* frontNode=que.front();
            que.pop();
            
            //checks whether the flow is left to right or right to left
            int index=LeftToRight? i:size-i-1;
            ans[index]=frontNode->data;

            if(frontNode->left){
                que.push(frontNode->left);
            }

            if(frontNode->right){
                que.push(frontNode->right);
            }
        }

        //change the direction for zig-zag traversal
        LeftToRight=!LeftToRight;

        //pushing the elements in result
        for(auto i:ans){
            result.push_back(i);
        }
    
    }
    return result;
}

int main() {
    Node* root = NULL;
    root = buildtree(root);

    cout << "Zigzag Traversal: ";
    vector<int> zigzagResult = zigzagTraversal(root);
    for (int i = 0; i < zigzagResult.size(); i++) {
        cout << zigzagResult[i];
        if (i != zigzagResult.size() - 1) {
            cout << " -> ";
        }
    }
    cout << endl;

    return 0;
}

//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1