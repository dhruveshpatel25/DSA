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

Node* LCAInBST(Node* root, Node* node1,Node* node2){
    while(root!=NULL){
        if(root->data<node1->data && root->data<node2->data){
            root=root->right;
        }
        else if(root->data>node1->data && root->data>node2->data){
            root=root->left;
        }else{
            return root;
        }
    }
}

int main() {
    Node* root = NULL;
    cout << "Enter elements to create BST: "<<endl;
    takeInput(root);

    cout << "Level Order Traversal of the BST:"<<endl;
    levelOrderTraversal(root);

    int node1_data, node2_data;
    cout << "Enter the data of two nodes to find their Lowest Common Ancestor: ";
    cin >> node1_data >> node2_data;

    Node* node1 = new Node(node1_data);
    Node* node2 = new Node(node2_data);

    Node* lca = LCAInBST(root, node1, node2);
    if (lca != NULL) {
        cout << "The Lowest Common Ancestor of " << node1_data << " and " << node2_data << " is: " << lca->data << endl;
    } else {
        cout << "One or both of the nodes not found in the BST.";
    }

    return 0;
}
