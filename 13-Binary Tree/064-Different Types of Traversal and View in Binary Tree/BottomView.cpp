/*Bottom View of Binary Tree
Given a binary tree, return an array where elements represent the bottom view of the binary tree from left to right.
Note: If there are multiple bottom-most nodes for a horizontal distance from the root, then the latter one in the level traversal is considered. For example, in the below diagram, 3 and 4 are both the bottommost nodes at a horizontal distance of 0, here 4 will be considered.

                      20
                    /    \
                  8       22
                /   \     /   \
              5      3 4     25
                     /    \      
                 10       14

For the above tree, the output should be 5 10 4 14 25.

Examples :

Input:
       1
     /   \
    3     2
Output: 3 1 2
Explanation: First case represents a tree with 3 nodes and 2 edges where root is 1, left child of 1 is 3 and right child of 1 is 2.
Thus bottom view of the binary tree will be 3 1 2.

Input:
         10
       /    \
      20    30
     /  \
    40   60
Output: 40 20 60 30

Input:
        1
       /   
      2
Output: 2 1
https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1*/
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

vector<int> bottomView(Node* root){
    vector<int> ans;
    if(root==NULL){
        return ans;
    }

    //mapping for every horizontal distance with one node
    map<int,int> BottomNode; //<horizontal distance,node->data>

    //queue for every node with horizontal distance
    queue<pair<Node*,int>> que;//<root,horizontal distance>

    //pushing root
    que.push(make_pair(root,0));
    while(!que.empty()){

        //get the front node from queue
        pair<Node*,int> temp = que.front();
        que.pop();

        //store the front node as frontnode
        Node* frontNode = temp.first;

        //store the distance as horizontal distance
        int horizontaldistance=temp.second;

        //cancel the previous value for particular horizontal distance
        BottomNode[horizontaldistance] = frontNode->data;

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
    for(auto i:BottomNode){

        //push the data value 
        ans.push_back(i.second);
    }
    return ans;
}

int main() {
    Node* root = NULL;
    root = buildtree(root);

    cout << "Bottom view of the binary tree: ";
    vector<int> result = bottomView(root);
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}

//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1