#include<iostream>
#include<queue>
#include<stack>
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

vector<int> zigzagTraversal(Node* root){
    vector<int> result;
    if(root==NULL){
        return result;
    }
    queue<Node*> que;
    que.push(root);
    bool LeftToRight=true;
    while(!que.empty()){
        int size=que.size();
        vector<int> ans(size);

        for(int i=0;i<size;i++){
            Node* frontNode=que.front();
            que.pop();
            
            int index=LeftToRight? i:size-i-1;
            ans[index]=frontNode->data;

            if(frontNode->left){
                que.push(frontNode->left);
            }

            if(frontNode->right){
                que.push(frontNode->right);
            }
        }
        LeftToRight=!LeftToRight;
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
