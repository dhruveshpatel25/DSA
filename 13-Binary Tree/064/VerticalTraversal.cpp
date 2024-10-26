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

vector<int> verticalTraversal(Node* root){
    map<int,map<int,vector<int> > > nodes; //<horizontal distance<level,node>>
    queue< pair<Node*,pair<int,int> > > que; //<root,<horizontal distance,level>>
    vector<int> ans;

    if(root==NULL){
        return ans;
    }

    que.push(make_pair(root,make_pair(0,0)));

    while(!que.empty()){
        pair<Node* ,pair<int,int> >temp=que.front(); //same as que
        que.pop();
        Node* frontNode=temp.first;
        int horizontaldistance=temp.second.first;
        int level=temp.second.second;

        nodes[horizontaldistance][level].push_back(frontNode->data);

        if(frontNode->left){
            que.push(make_pair(frontNode->left,make_pair(horizontaldistance-1,level+1)));
        }

        if(frontNode->right){
            que.push(make_pair(frontNode->right,make_pair(horizontaldistance+1,level+1)));
        }
    }
    for(auto i: nodes){
        for(auto j:i.second){
            for(auto k:j.second){
                ans.push_back(k);
            }
        }
    }
    return ans;
}

int main() {
    Node* root = NULL;
    root = buildtree(root);

    cout << "Vertical Traversal of the binary tree: ";
    vector<int> result = verticalTraversal(root);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
