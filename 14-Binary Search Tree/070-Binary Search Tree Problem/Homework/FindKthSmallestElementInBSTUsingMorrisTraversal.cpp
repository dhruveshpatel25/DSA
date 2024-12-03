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

    //iterate to right if the data is greater than the root data
    if(data>root->data){
        root->right = insertToBST(root->right,data);
    }else{ //iterate to left if the data is smaller than the root data
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

int KthSmallestUsingMorrisTraversal(Node* root,int k){
    Node* curr=root;
    int count=0;
    while(curr!=NULL){

        //if there exist no left subtree below current root node
        if(curr->left==NULL){

            //increment the count
            count++;

            //if we reach k then return the data
            if(count==k){
                return curr->data;
            }

            //move to right subtree to find greater value than the current root
            curr=curr->right;
        }else{ //if the current root node has a left subtree
            Node* pred=curr->left;

            //move to right subtree of predecessor node or stop if the thread exit
            while(pred->right!=NULL && pred->right!=curr){
                pred=pred->right;
            }

            //if thread does not exist then establish a thread between the predecessor and current
            if(pred->right==NULL){
                pred->right=curr;

                //move to the left subtree of current node 
                curr=curr->left; 
            }else{ //if thread exist remove the thread
                pred->right=NULL;
                count++;
                if(count==k){
                    return curr->data;
                }
                curr=curr->right;
            }
        }
    }
}
int main() {
    Node* root = NULL;

    cout << "Enter elements to insert into the BST (terminate with -1): " << endl;
    takeInput(root);

    int k;
    cout << "Enter the value of k to find the kth smallest element: ";
    cin >> k;

    int kthSmallestElement = KthSmallestUsingMorrisTraversal(root, k);
    if (kthSmallestElement != -1) {
        cout << "The " << k << "th smallest element in the BST is: " << kthSmallestElement << endl;
    } else {
        cout << "Invalid value of k!" << endl;
    }

    return 0;
}

// 10 8 21 7 27 5 4 3 -1