/*Remove duplicates from a sorted Doubly Linked List
A doubly-linked list is a data structure that consists of sequentially linked nodes, and the nodes have reference to both the previous and the next nodes in the sequence of nodes.
You are given a sorted doubly linked list of size 'n'.
Remove all the duplicate nodes present in the linked list.

Example :
Input: Linked List: 1 <-> 2 <-> 2 <-> 2 <-> 3
Output: Modified Linked List: 1 <-> 2 <-> 3
Explanation: We will delete the duplicate values ‘2’ present in the linked list.
https://www.naukri.com/code360/problems/remove-duplicates-from-a-sorted-doubly-linked-list_2420283*/
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    //constructor
    Node(int data){
        this->data=data;
        this->next=NULL;
    }

    //destructor
    ~Node(){

        //first save the value
        int value = this->data;

        //if not the last node
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
    }
};

Node * RemoveDuplicateSorted(Node* &head){

    //if no node
    if(head==NULL){
        return NULL;
    }

    //pointer at head
    Node * curr=head;

    //iterate till last node
    while(curr!=NULL){

        //if not last node and next node data is same as current node 
        if(curr->next!=NULL && curr->data==curr->next->data){

            //pointer on next of next node
            Node* temp = curr->next->next;

            //pointer on delete node
            Node *todelete = curr->next;

            //delete
            delete(todelete);

            //pointer on the next to next node
            curr->next = temp;
        }
        else{

            //just iterate ahead
            curr=curr->next;
        }
    }
    return head;
}

void InsertAtTail(Node* &tail,int d){

    //make a new node
    Node* temp=new Node(d);

    //make the last node's next point towars tail of LL
    tail->next=temp;

    //move tail to new node
    tail=temp;
}

void print(Node* &head){
    Node* temp= head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    Node* node1= new Node(1);
    Node* head=node1;
    Node* tail=node1;
    InsertAtTail(tail,2);
    InsertAtTail(tail,2);
    InsertAtTail(tail,3);
    print(head);
    RemoveDuplicateSorted(head);
    print(head); 
}