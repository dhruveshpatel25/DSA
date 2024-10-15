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

Node* solve(vector<int> &preorder,int mini,int maxi,int &i){
    if(i>=preorder.size()){
        return NULL;
    }
    if(preorder[i]<mini || preorder[i]>maxi){
        return NULL;
    }
    Node* root=new Node(preorder[i++]);
    root->left = solve(preorder,mini,root->data,i);
    root->right = solve(preorder,root->data,maxi,i);
    return root;
}

Node* preorderToBST(vector<int> &preorder){
    int mini=INT_MIN;
    int maxi=INT_MAX;
    int i=0;
    return solve(preorder,mini,maxi,i);
}

int main() {
    // Taking input for preorder traversal
    int n;
    cout << "Enter number of elements in preorder traversal: ";
    cin >> n;

    vector<int> preorder(n);
    cout << "Enter elements for preorder traversal: ";
    for (int i = 0; i < n; i++) {
        cin >> preorder[i];
    }

    // Constructing BST from preorder traversal
    Node* root = preorderToBST(preorder);

    // Printing level order traversal of newly constructed BST
    cout << "Level Order Traversal of Constructed BST:" << endl;
    levelOrderTraversal(root);

    return 0;
}

