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

Node* createParentMapping(Node* root,int target,map<Node*,Node*> &NodeToParent){
    Node* res=NULL;
    queue<Node*> que;
    que.push(root);
    NodeToParent[root]=NULL;
    while(!que.empty()){
        Node* front=que.front();
        que.pop();
        if(front->data==target){
            res=front;
        }

        if(front->left){
            NodeToParent[front->left]=front;
            que.push(front->left);
        }

        if(front->right){
            NodeToParent[front->right]=front;
            que.push(front->right);
        }
    }
    return res;
}

int BurnTree(Node* root,map<Node*,Node*> &NodeToParent){
    map<Node*,bool> visited;
    queue<Node*> que;
    que.push(root);
    visited[root]=true;
    int time=0;
    while(!que.empty()){
        bool flag=0;
        int size=que.size();
        for(int i=0;i<size;i++){
            Node* front=que.front();
            que.pop();

            if(front->left && !visited[front->left]){
                flag=1;
                que.push(front->left);
                visited[front->left]=true;
            }

            if(front->right && !visited[front->right]){
                flag=1;
                que.push(front->right);
                visited[front->right]=true;
            }

            if(NodeToParent[front] && !visited[NodeToParent[front]]){
                flag=1;
                que.push(NodeToParent[front]);
                visited[NodeToParent[front]];
            }

            if(flag==1){
                time++;
            }
        }
    }
    return time;
}

int minTime(Node* root,int target){
    map<Node*,Node*> NodeToParent;
    Node* targetNode=createParentMapping(root,target,NodeToParent);

    int ans=BurnTree(root,NodeToParent);
    return ans;
}

int main() {
    Node* root = NULL;
    root = buildtree(root); // Build the binary tree

    int target;
    cout << "Enter the target node from where fire starts: ";
    cin >> target;

    int time = minTime(root, target); // Calculate the minimum time to burn the tree
    cout << "Minimum time to burn the entire tree: " << time << endl;

    return 0;
}
