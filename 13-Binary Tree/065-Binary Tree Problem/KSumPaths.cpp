#include<iostream>
#include<queue>
#include<stack>
#include<map>
#include<climits>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
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

void solve(Node* root,int k,int &count,vector<int> path){

    //base case
    if(root==NULL){
        return;
    }

    //push the nodes in path array
    path.push_back(root->data);

    //recursively iterate to left subtree
    solve(root->left,k,count,path);

    //recursively iterate to right subtree
    solve(root->right,k,count,path);

    //get size of path array
    int size=path.size();

    //initialise the sum
    int sum=0;

    //calculate the sum of the path
    for(int i=size-1;i>=0;i--){
        sum=sum+path[i];

        //if the sum matches the k then incease the count
        if(sum==k){
            count++;
        }
        
        //remove the node from path array
        path.pop_back();
    }

}

int kSumPaths(Node* root,int k){
    vector<int> path;
    int count=0;
    solve(root,k,count,path);
    return count;
}

int main() {
    Node* root = NULL;
    root = buildtree(root);

    int k;
    cout << "Enter the value of k: ";
    cin >> k;

    int result = kSumPaths(root, k);
    cout << "Number of paths with sum " << k << ": " << result << endl;

    return 0;
}
//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1