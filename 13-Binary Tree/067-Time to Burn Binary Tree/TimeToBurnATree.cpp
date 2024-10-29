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

    //so we can do level order traversal
    queue<Node*> que;
    que.push(root);

    //making the parent og root node as NULL
    NodeToParent[root]=NULL;
    while(!que.empty()){
        Node* front=que.front();
        que.pop();

        //target node found
        if(front->data==target){
            res=front;
        }

        //create mapping for left child to parent node
        if(front->left){
            NodeToParent[front->left]=front;
            que.push(front->left);
        }

        //create mapping for right child to parent node
        if(front->right){
            NodeToParent[front->right]=front;
            que.push(front->right);
        }
    }
    return res;
}

int BurnTree(Node* root,map<Node*,Node*> &NodeToParent){

    //to check if the node is burned or not
    map<Node*,bool> visited;

    //for level order traversal
    queue<Node*> que;

    //push the target node
    que.push(root);

    //make the target node as visisted
    visited[root]=true;

    //start the timer
    int time=0;
    while(!que.empty()){
        bool flag=0;
        int size=que.size();

        //to check neighbouring node for all the nodes present in queue
        for(int i=0;i<size;i++){
            Node* front=que.front();
            que.pop();

            //check if left child is present and check wheter it is visited or not
            if(front->left && !visited[front->left]){
                flag=1;
                que.push(front->left);
                visited[front->left]=true;
            }

            //check if right child is present and check wheter it is visited or not
            if(front->right && !visited[front->right]){
                flag=1;
                que.push(front->right);
                visited[front->right]=true;
            }

            //check if parent is present and check wheter it is visited or not
            if(NodeToParent[front] && !visited[NodeToParent[front]]){
                flag=1;
                que.push(NodeToParent[front]);
                visited[NodeToParent[front]]=true;
            }

        }
        //after burning neighbouring node increase the time counter
        if(flag==1){
            time++;
        }
    }
    return time;
}

int minTime(Node* root,int target){

    //create nodeToParent mapping
    map<Node*,Node*> NodeToParent;

    //to start the the fire from
    Node* targetNode=createParentMapping(root,target,NodeToParent);

    int ans=BurnTree(targetNode,NodeToParent);
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

//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1