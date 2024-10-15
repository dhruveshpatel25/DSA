#include<iostream>
#include<queue>
#include<stack>
#include<map>
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

vector<int> diagonalTraversal(Node* root){
    vector<int> ans;
    queue<Node*> que;
    if(root==NULL){
        return ans;
    }
    que.push(root);
    while(!que.empty()){
        Node* temp=que.front();
        que.pop();
        while(temp){
            if(temp->left){
                que.push(temp->left);
            }
            ans.push_back(temp->data);
            temp=temp->right;
        }
    }
    return ans;
}

int main() {
    Node* root = NULL;
    root = buildtree(root);

    cout << "Diagonal Traversal of the binary tree: ";
    vector<int> diagonalResult = diagonalTraversal(root);
    for (int i = 0; i < diagonalResult.size(); ++i) {
        cout << diagonalResult[i] << " ";
    }
    cout << endl;

    return 0;
}