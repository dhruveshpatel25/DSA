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

    //store the answer
    vector<int> ans;

    //for breadth-first search
    queue<Node*> que;

    //base case
    if(root==NULL){
        return ans;
    }

    //push the root node
    que.push(root);
    while(!que.empty()){
        Node* temp=que.front();
        que.pop();

        //process each node along the diagonal line
        while(temp){

            //if there is left child for that node put it to next diagonal line
            if(temp->left){
                que.push(temp->left);
            }

            //add the data of current node to answer
            ans.push_back(temp->data);

            //iterate to next node along diagonal
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

//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1