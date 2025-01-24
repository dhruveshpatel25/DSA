/*Huffman Encoding
Given a string S of distinct character of size N and their corresponding frequency f[ ] i.e. character S[i] has f[i] frequency. Your task is to build the Huffman tree print all the huffman codes in preorder traversal of the tree.
Note: While merging if two nodes have the same value, then the node which occurs at first will be taken on the left of Binary Tree and the other one to the right, otherwise Node with less value will be taken on the left of the subtree and other one to the right.

Example 1:
S = "abcdef"
f[] = {5, 9, 12, 13, 16, 45}
Output: 
0 100 101 1100 1101 111
HuffmanCodes will be:
f : 0
c : 100
d : 101
a : 1100
b : 1101
e : 111
Hence printing them in the PreOrder of Binary Tree.
https://www.geeksforgeeks.org/problems/huffman-encoding3345/1*/
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;

    //left child node
    Node* left;

    //right child node
    Node* right;

    Node (int d){
        data=d;
        left=NULL;
        right=NULL;
    } 
};

class cmp{
    public:
    bool operator()(Node* a,Node* b){

        //save the lowest value first
        return a->data>b->data;
    }
};

void traverse(Node* root,vector<string>& ans,string temp){

    //when reached lead node
    if(root->left==NULL && root->right==NULL){
        ans.push_back(temp);
        return;
    }

    //recursivly call the left subtree by adding 0 to answer
    traverse(root->left,ans,temp+'0');

    //recursivly call the right subtree by adding 1 to answer
    traverse(root->right,ans,temp+'1');
}
vector<string> huffmanCodes(string S,vector<int> f,int N){
	priority_queue<Node*,vector<Node*>,cmp>pq;

    //iterate the complete string
    for(int i=0;i<N;i++){
        Node* temp=new Node(f[i]);
        pq.push(temp);
    }

    //till one sum is left add the lowest together
    while(pq.size()>1){

        //first element
        Node* left=pq.top();
        pq.pop();

        //second element
        Node* right=pq.top();
        pq.pop();

        //add the sum of data
        Node* newNode=new Node(left->data+right->data);

        //left subtree with left (lower value) node
        newNode->left=left;

        //right subtree with right (higher value) node
        newNode->right=right;

        //push in priority queue
        pq.push(newNode);
    }

    Node* root=pq.top();
    vector<string> ans;

    //temporary saving the answer
    string temp="";
    traverse(root,ans,temp);
    return ans;
}

int main() {
    string S = "abcdef";
    vector<int> f = {5, 9, 12, 13, 16, 45};
    int N = S.size();

    vector<string> codes = huffmanCodes(S, f, N);

    cout << "Huffman Codes in PreOrder Traversal:" << endl;
    for (int i = 0; i < N; i++) {
        cout << codes[i] << endl;
    }

    return 0;
}