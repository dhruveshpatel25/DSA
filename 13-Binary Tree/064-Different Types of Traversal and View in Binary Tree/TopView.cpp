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

vector<int> topview(Node* root){
    vector<int> ans;
    if(root==NULL){
        return ans;
    }

    //mapping for every horizontal distance with one node
    map<int,int> TopNode; //<horizontal distance,node->data>

    //queue for every node with horizontal distance
    queue<pair<Node*,int>> que; //<root,horizontal distance>

    //pushing root
    que.push(make_pair(root,0));
    while(!que.empty()){

        //get the front node from queue
        pair<Node*,int>temp=que.front();
        que.pop();

        //store the front node as frontnode
        Node* frontNode = temp.first;

        //store the distance as horizontal distance
        int horizontaldistance = temp.second;

        //check if there exist a node for that horizontal distance if not then save else skip it
        if(TopNode.find(horizontaldistance)==TopNode.end()){
            TopNode[horizontaldistance]=frontNode->data;
        }

        //iterate to left subtree while decresing the horizontal distance by 1
        if(frontNode->left){
            que.push(make_pair(frontNode->left,horizontaldistance-1));
        }

        //iterate to right subtree while increasing the horizontal distance by 1
        if(frontNode->right){
            que.push(make_pair(frontNode->right,horizontaldistance+1));
        }
    }

    //for every horizontal distance
    for(auto i:TopNode){
        
        //push the data value 
        ans.push_back(i.second);
    }
}

int main() {
    Node* root = NULL;
    root = buildtree(root);

    cout << "Top view of the binary tree: ";
    vector<int> result = topview(root);
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}

//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1