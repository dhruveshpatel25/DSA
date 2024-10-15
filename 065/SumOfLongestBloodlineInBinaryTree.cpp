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

void solve(Node* root,int len,int& Maxlen,int sum,int& Maxsum){
    if(root==NULL){
        if(len>Maxlen){
            Maxlen=len;
            Maxsum=sum;
        }
        else if(len==Maxlen){
            Maxsum=max(sum,Maxsum);
        }
        return;
    }
    sum=sum+root->data;
    solve(root->left,len+1,Maxlen,sum,Maxsum);
    solve(root->right,len+1,Maxlen,sum,Maxsum);
}

int sumOfLongRootToLeafPath(Node* root){
    int len=0;
    int Maxlen=0;

    int sum=0;
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