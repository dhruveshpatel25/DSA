/*Merge Two BSTs
You are given two binary search trees of integers having ‘N’ and ‘M’ nodes. Return an array that contains elements of both BST in sorted order.

A binary search tree (BST) is a binary tree data structure with the following properties.
    • The left subtree of a node contains only nodes with data less than the node’s data.
    • The right subtree of a node contains only nodes with data greater than the node’s data.
• Both the left and right subtrees must also be binary search trees.
https://www.naukri.com/code360/problems/h_920474*/
#include<iostream>
#include<queue>
#include<stack>
#include<map>
#include<climits>
using namespace std;

class Node{
    public:
    int data;

    //left subtree
    Node *left;

    //right subtree
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
    }else{ 
        
    //iterate to left if the data is smaller than the root data
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

//level order traversal-printing in tree form
void levelOrderTraversal(Node *root){
    queue<Node*> que;
    que.push(root);

    //separator-used to separate 2 levels in tree
    que.push(NULL);

    while(!que.empty()){
        Node* temp=que.front();
        que.pop();

        //last level is complete
        if(temp==NULL){ 
            cout<<endl;

            //queue still has child nodes
            if(!que.empty()){
                que.push(NULL);
            }
        }
        else
        { 
            cout<<temp->data<<" ";

            //pushing the left child
            if(temp->left){
                que.push(temp->left);
            }

            //pushing the right child
            if(temp->right){
                que.push(temp->right);
            }
        }
    }
}

void ConvertBSTToDoublyLinkedList(Node* root,Node* &head){

    //base case
    if(root==NULL){
        return;
    }

    //now we recursivly start with the rightmost node ie. the biggest value
    ConvertBSTToDoublyLinkedList(root->right,head);

    //make the right of root as head
    root->right=head;

    //check if the head(right of root) NULL or not
    if(head!=NULL){
        head->left=root;
    }

    //now shift hrad to root
    head=root;

    //now recursivly to the left subtree
    ConvertBSTToDoublyLinkedList(root->left,head);
}

Node* mergeLinkedlist(Node *head1, Node *head2){
    Node* head=NULL;
    Node* tail=NULL;

    //loop till both the linked list are merged
    while(head1!=NULL && head2!=NULL){

        //if head of first liked list is smaller
        if(head1->data<head2->data){


            //if it is first node
            if(head==NULL){

                //point head at the head1
                head=head1;

                //point tail at head1
                tail=head1;

                //now move the head1 to its next element
                head1=head1->right;


            }else{  //if it is not the first node

                //now enter the head1 from tail
                tail->right=head1;

                //now point the head1 to the previous element of new LL
                head1->left=tail;

                //now move tail pointer to the last element 
                tail=head1;

                //now move head1 to the next element of old LL
                head1=head1->right;
            }
        }else{  //if head of second linked list is smaller

            //if is is first node
            if(head==NULL){

                //point head at the head2
                head=head2;

                //point tail at head2
                tail=head2;

                //now move the head1 to its next element
                head2=head2->right;
            }else{ //if it is not the first node

                //now enter the head2 from tail
                tail->right=head2;

                //now point the head2 to the previous element of new LL
                head2->left=tail;

                //now move tail pointer to the last element 
                tail=head2;

                //now move head2 to the next element of old LL
                head2=head2->right;
            }
        }
    }

    //if only the first linked list is left
    while(head1!=NULL){

        //now enter the head1 from tail
        tail->right=head1;

        //now point the head1 to the previous element of new LL
        head1->left=tail;

        //now move tail pointer to the last element 
        tail=head1;

        //now move head1 to the next element of old LL
        head1=head1->right;
    }

    //if only the second linked list is left
    while(head2!=NULL){

        //now enter the head2 from tail
        tail->right=head2;

        //now point the head2 to the previous element of new LL
        head2->left=tail;

        //now move tail pointer to the last element
        tail=head2;

        //now move head2 to the next element of old LL
        head2=head2->right;
    }

    return head;
}

//count the no of nodes in LL
int countNodes(Node* head){
    int count=0;
    Node* temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->right;
    }
    return count;
}

Node* LinkedListToBST(Node* &head,int nodes){
    if(nodes<=0 || head==NULL){
        return NULL;
    }

    //recursivly iterate left subtree
    Node* left = LinkedListToBST(head,nodes/2);

    //make the head as root
    Node* root = head;

    //Now point the left pointer of tree to left subtree
    root->left=left;

    //now check for right subtree
    head=head->right;

    //recursivly iterate right subtree
    root->right =LinkedListToBST(head,nodes-nodes/2-1);
    return root; 
}

Node* merge2BST(Node* root1,Node* root2){

    //convert the first BST to LL
    Node* head1=NULL;
    ConvertBSTToDoublyLinkedList(root1,head1);
    head1->left=NULL;

    //convert the second BST to LL
    Node* head2=NULL;
    ConvertBSTToDoublyLinkedList(root2,head2);
    head2->left=NULL;

    //merge the 2 LL
    Node* head=mergeLinkedlist(head1,head2);

    //count the no. of nodes in LL
    int countNode = countNodes(head);

    //convert the LL to BST
    return LinkedListToBST(head,countNode);
}

int main() {
    // Input and create first BST
    Node* root1 = NULL;
    cout << "Enter elements for the first BST (end with -1): " << endl;
    takeInput(root1);

    cout << "Level Order Traversal of the first BST:" << endl;
    levelOrderTraversal(root1);

    // Input and create second BST
    Node* root2 = NULL;
    cout << "Enter elements for the second BST (end with -1): " << endl;
    takeInput(root2);

    cout << "Level Order Traversal of the second BST:" << endl;
    levelOrderTraversal(root2);

    // Merge the two BSTs
    Node* mergedRoot = merge2BST(root1, root2);

    cout << "Level Order Traversal of the merged BST:" << endl;
    levelOrderTraversal(mergedRoot);

    return 0;
}

//10 5 15 3 7 -1
//20 18 25 -1 