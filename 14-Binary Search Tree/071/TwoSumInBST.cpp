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

void Inorder(Node* root,vector<int> &inorderval){  //Left Node->Root Node->Right Node
    if(root==NULL){
        return;
    }

    Inorder(root->left,inorderval);
    inorderval.push_back(root->data);
    Inorder(root->right,inorderval);
}

bool twoSumInBST(Node* root,int target){
    vector<int> inorderval;
    Inorder(root,inorderval);
    int i=0;
    int j=inorderval.size()-1;

    while(i<j){
        int sum=inorderval[i]+inorderval[j];
        if(sum==target){
            return true;
        }else if(sum>target){
            j--;
        }else{
            i++;
        }
    }
    return false;
}

int main() {
    Node* root = NULL;
    cout << "Enter elements to insert into BST: ";
    takeInput(root);

    cout << "Level Order Traversal of BST: " << endl;
    levelOrderTraversal(root);

    int target;
    cout << "Enter the target sum: ";
    cin >> target;

    if (twoSumInBST(root, target)) {
        cout << "There exist two elements in the BST that sum up to " << target << "." << endl;
    } else {
        cout << "No two elements in the BST sum up to " << target << "." << endl;
    }

    return 0;
}
