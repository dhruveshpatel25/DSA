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

void levelOrderTraversal(Node *root){
    queue<Node*> que;
    que.push(root);
    que.push(NULL);

    while(!que.empty()){
        Node* temp=que.front();
        que.pop();

        if(temp==NULL){ //last level is complete
            cout<<endl;
            if(!que.empty()){
                que.push(NULL);
            }
        }
        else
        { 
            cout<<temp->data<<" ";
            if(temp->left){
                que.push(temp->left);
            }

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

    int left=solve(root->left,i,k);
    if(left!=-1){
        return left;
    }
    i++;
    if(i==k){
        return root->data;
    }
    return solve(root->right,i,k);
}

int kthSmallest(Node* root,int i,int k){
    i=0;
    int ans=solve(root,i,k);
    return ans;
}

Node* insertToBST(Node* root,int data){
    if(root==NULL){
        root=new Node(data);
        return root;
    }

    if(data>root->data){
        root->right = insertToBST(root->right,data);
    }else{
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
    cout << "Enter the value of k to find the kth smallest element: ";
    cin >> k;

    int kthSmallestElement = kthSmallest(root, 0, k);
    cout << "The " << k << "th smallest element in the BST is: " << kthSmallestElement << endl;

    return 0;
}
