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

Node* buildtree(Node *root){
    cout<<"Enter the data: "<<endl;
    int data;
    cin>>data;
    root=new Node(data);
    if(data==-1){
        return NULL;
    }

    cout<<"Enter the data for inserting in left of "<<data<<endl;
    root->left=buildtree(root->left);
    cout<<"Enter the data for inserting in right of "<<data<<endl;
    root->right=buildtree(root->right);
    return root;
}

//level order traversal-printing in tree form
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

void Inorder(Node* root,vector<int> &inorderval){  //Left Node->Root Node->Right Node
    if(root==NULL){
        return;
    }

    Inorder(root->left,inorderval);
    inorderval.push_back(root->data);
    Inorder(root->right,inorderval);
}

Node* convertToBalancedBST(int start,int end,vector<int> &inorderval){
    if(start>end){
        return NULL;
    }

    int mid=(start+end)/2;
    Node* newroot=new Node(inorderval[mid]);
    newroot->left=convertToBalancedBST(start,mid-1,inorderval);
    newroot->right=convertToBalancedBST(mid+1,end,inorderval);
    return newroot;
}

Node* balancedBST(Node* root){
    vector<int> inorderval;
    Inorder(root,inorderval);
    return convertToBalancedBST(0,inorderval.size()-1,inorderval);
}

int main() {
    Node* root = NULL;

    cout << "Enter elements to insert into the BST (-1 to stop):" << endl;
    root=buildtree(root);

    cout << "Original BST (Level Order Traversal):" << endl;
    levelOrderTraversal(root);

    root = balancedBST(root);

    cout << "Balanced BST (Level Order Traversal):" << endl;
    levelOrderTraversal(root);

    return 0;
}
