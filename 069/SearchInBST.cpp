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

bool searchInBSTUsingRecursion(Node *root,int data){
    if(root==NULL){
        return false;
    }

    if(root->data==data){
        return true;
    }

    if(root->data>data){
        searchInBSTUsingRecursion(root->left,data);
    }else{
        searchInBSTUsingRecursion(root->right,data);
    }
}

bool searchInBSTUsingIteration(Node* root,int data){
    Node* temp=root;
    while(temp!=NULL){
        if(temp==NULL){
            return false;
        }
        if(temp->data==data){
            return true;
        }
        if(temp->data>data){
            temp=temp->left;
        }else{
            temp=temp->right;
        }
    }
    return false;
}

int main() {
    Node* root = NULL;
    
    cout << "Enter elements to insert into BST: " << endl;
    takeInput(root);
    
    int searchDataRecursion;
    cout << "Enter a value to search in BST using recursion: ";
    cin >> searchDataRecursion;
    if (searchInBSTUsingRecursion(root, searchDataRecursion)) {
        cout << searchDataRecursion << " found in BST using recursion." << endl;
    } else {
        cout << searchDataRecursion << " not found in BST using recursion." << endl;
    }

    int searchDataIteration;
    cout << "Enter a value to search in BST using iteration: ";
    cin >> searchDataIteration;
    if (searchInBSTUsingIteration(root, searchDataIteration)) {
        cout << searchDataIteration << " found in BST using iteration." << endl;
    } else {
        cout << searchDataIteration << " not found in BST using iteration." << endl;
    }

    return 0;
}
// 10 8 21 7 27 5 4 3 -1