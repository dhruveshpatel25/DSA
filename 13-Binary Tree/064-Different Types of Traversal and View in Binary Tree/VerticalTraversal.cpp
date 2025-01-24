/*Vertical Tree Traversal
Given a Binary Tree, find the vertical traversal of it starting from the leftmost level to the rightmost level.
If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level order traversal of the tree.

Examples:

Input: root = [1, 2, 3, 4, 5, 6, 7, N, N, N, N, N, 8, N, 9]

 Vertical-Taversal-          
Output: [4, 2, 1, 5, 6, 3, 8, 7, 9] 
Explanation: from left to right the vertical order will be [4, 2, 1, 5, 6, 3, 8, 7, 9] 

Input: root = [1, 2, 3, 4, 5, N, 6]

       1
    /    \
   2       3
 /    \      \
4      5      6
Output: [4, 2, 1, 5, 3, 6]
Explanation: from left to right the vertical order will be [4, 2, 1, 5, 3, 6]

Input: root = [7, 2, 3, 4, 5, N, 6]
     7
    /    \
   2       3
 /    \      \
4      5      6
Output: [4, 2, 7, 5, 3, 6]
Explanation: from left to right the vertical order will be [4, 2, 7, 5, 3, 6]
https://www.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1*/
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

vector<int> verticalTraversal(Node* root){

    //map for retrieving the data according to its horizontal distance and level
    map<int,map<int,vector<int> > > nodes; //<horizontal distance<level,node>>

    //queue which contains the data of particular node
    queue< pair<Node*,pair<int,int> > > que; //<root,<horizontal distance,level>>

    //saving the nodes
    vector<int> ans;

    if(root==NULL){
        return ans;
    }

    que.push(make_pair(root,make_pair(0,0))); //root-node,horizontal distance,depth

    while(!que.empty()){

        //retrieve the front node data from queue
        pair<Node* ,pair<int,int> >temp=que.front(); //same as que 
        que.pop();

        //store the node as frontnode
        Node* frontNode=temp.first;

        //store its distance as horizontal distance
        int horizontaldistance=temp.second.first;

        //store its level from top as level
        int level=temp.second.second;

        //maps for each horizontal distance and in it maps with level
        nodes[horizontaldistance][level].push_back(frontNode->data);

        //iterate to left subtree while decresing the horizontal distance by 1 and increasing the level by 1
        if(frontNode->left){
            que.push(make_pair(frontNode->left,make_pair(horizontaldistance-1,level+1)));
        }

        //iterate to right subtree while increasing the horizontal distance by 1 and increasing the level by 1
        if(frontNode->right){
            que.push(make_pair(frontNode->right,make_pair(horizontaldistance+1,level+1)));
        }
    }

    // for every horizontal distance
    for(auto i: nodes){

        //for every level present in particular distance
        for(auto j:i.second){

            //for every node value present in particular level  
            for(auto k:j.second){
                ans.push_back(k);
            }
        }
    }
    return ans;
}

int main() {
    Node* root = NULL;
    root = buildtree(root);

    cout << "Vertical Traversal of the binary tree: ";
    vector<int> result = verticalTraversal(root);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}

//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1