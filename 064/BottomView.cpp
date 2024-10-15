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

vector<int> bottomView(Node* root){
    vector<int> ans;
    if(root==NULL){
        return ans;
    }

    map<int,int> BottomNode;
    queue<pair<Node*,int>> que;

    que.push(make_pair(root,0));
    while(!que.empty()){
        pair<Node*,int> temp = que.front();
        que.pop();
        Node* frontNode = temp.first;
        int horizontaldistance=temp.second;

        BottomNode[horizontaldistance] = frontNode->data;

        if(frontNode->left){
            que.push(make_pair(frontNode->left,horizontaldistance-1));
        }

        if(frontNode->right){
            que.push(make_pair(frontNode->right,horizontaldistance+1));
        }

    }
    for(auto i:BottomNode){
        ans.push_back(i.second);
    }
    return ans;
}

int main() {
    Node* root = NULL;
    root = buildtree(root);

    cout << "Bottom view of the binary tree: ";
    vector<int> result = bottomView(root);
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}