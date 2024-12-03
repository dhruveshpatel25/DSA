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

Node* mini(Node* root){
    Node* temp=root;

    //iterate till you find the minimum value
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}

Node *maxi(Node* root){
    Node* temp=root;

    //iterate till you find the maximum value
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp;
}

int main() {
    Node* root = NULL;

    // Taking input to construct the BST
    cout << "Enter elements to insert into the BST (-1 to end):" << endl;
    takeInput(root);

    // Finding the minimum element in the BST
    if (root != NULL) {
        Node* minNode = mini(root);
        cout << "Minimum element in the BST: " << minNode->data << endl;
    } else {
        cout << "BST is empty. No minimum element." << endl;
    }

    // Finding the maximum element in the BST
    if (root != NULL) {
        Node* maxNode = maxi(root);
        cout << "Maximum element in the BST: " << maxNode->data << endl;
    } else {
        cout << "BST is empty. No maximum element." << endl;
    }

    return 0;
}
// 10 8 21 7 27 5 4 3 -1