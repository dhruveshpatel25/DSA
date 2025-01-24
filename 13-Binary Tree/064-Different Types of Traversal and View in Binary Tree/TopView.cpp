/*Top View of Binary Tree
You are given a binary tree, and your task is to return its top view. The top view of a binary tree is the set of nodes visible when the tree is viewed from the top.

Note: 
Return the nodes from the leftmost node to the rightmost node.
If two nodes are at the same position (horizontal distance) and are outside the shadow of the tree, consider the leftmost node only. 

Examples:

Input: root[] = [1, 2, 3] 
Output: [2, 1, 3]

Input: root[] = [10, 20, 30, 40, 60, 90, 100]
Output: [40, 20, 10, 30, 100]
Explaination: The root 10 is visible.
On the left, 40 is the leftmost node and visible, followed by 20.
On the right, 30 and 100 are visible. Thus, the top view is 40 20 10 30 100.

Input: root[] = [1, 2, 3, N, 4, N, N, N, 5, N, 6]
       1
     /   \
    2     3
     \   
      4
       \
        5
         \
          6
Output: [2, 1, 3, 6]
Explaination: Node 1 is the root and visible.
Node 2 is the left child and visible from the left side.
Node 3 is the right child and visible from the right side.
Nodes 4, 5, and 6 are vertically aligned, but only the lowest node 6 is visible from the top view. Thus, the top view is 2 1 3 6.
https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1*/
#include<iostream>
#include<queue>
#include<stack>
#include<map>
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

vector<int> topview(Node* root){
    vector<int> ans;
    if(root==NULL){
        return ans;
    }

    //mapping for every horizontal distance with one node
    map<int,int> TopNode; //<horizontal distance,node->data>

    //queue for every node with horizontal distance
    queue<pair<Node*,int>> que; //<root,horizontal distance>

    //pushing root
    que.push(make_pair(root,0));
    while(!que.empty()){

        //get the front node from queue
        pair<Node*,int>temp=que.front();
        que.pop();

        //store the front node as frontnode
        Node* frontNode = temp.first;

        //store the distance as horizontal distance
        int horizontaldistance = temp.second;

        //check if there exist a node for that horizontal distance if not then save else skip it
        if(TopNode.find(horizontaldistance)==TopNode.end()){
            TopNode[horizontaldistance]=frontNode->data;
        }

        //iterate to left subtree while decresing the horizontal distance by 1
        if(frontNode->left){
            que.push(make_pair(frontNode->left,horizontaldistance-1));
        }

        //iterate to right subtree while increasing the horizontal distance by 1
        if(frontNode->right){
            que.push(make_pair(frontNode->right,horizontaldistance+1));
        }
    }

    //for every horizontal distance
    for(auto i:TopNode){
        
        //push the data value 
        ans.push_back(i.second);
    }
}

int main() {
    Node* root = NULL;
    root = buildtree(root);

    cout << "Top view of the binary tree: ";
    vector<int> result = topview(root);
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}

//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1