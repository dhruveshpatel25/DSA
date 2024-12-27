/*Split A Circular Linked List
You are given a circular linked list having N number of nodes, where N is even. You have to split this linked list into two equal-sized circular linked lists.
Here splitting means you have to make two separate circular linked lists, one for the first N/2 nodes and one for the last N/2 nodes.

For Example :
Let the circular linked list be 1, 2, 3, 4. We have to split this into two equal-sized circular linked lists.
https://www.naukri.com/code360/problems/split-a-circular-linked-list_1071003*/
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

Node* Split(Node* head){

    //if no node or 1 node
    if(head == NULL || head->next==head){
        return head;
    }

    //pointers
    Node* slow = head;
    Node* fast = head;

        //for odd length        for even length
    while(fast->next!=head && fast->next->next!=head){

        //slow pointer one step at a time
        slow=slow->next;

        //fast pointer two step at a time
        fast=fast->next->next;
    }
    
    //adjusting for even length
    if(fast->next->next==head){

        //if next to next is head just take one step
        fast=fast->next;
    }

    //new head on next of slow pointer
    Node* head2=slow->next;

    //now the last node of orignal LL will point to head2
    fast->next=head2;

    //now 
    slow->next=head;    
    return head2;
}

void InsertAtTail(Node* &head, Node* &tail, int data){

    //if no node in LL
    if(tail==NULL){

        //make a new node
        Node* temp=new Node(data);

        //pointer at tail
        tail=temp;

        //to make it circular
        temp->next=temp;
    }else{

        //make a new node
        Node* temp=new Node(data);

        //tail's next will point to new node
        tail->next=temp;

        //new node's next will be head to make it circular
        temp->next=head;

        //tail pointer on new node
        tail=temp;
    }
}

void print(Node* &head,Node* &tail){
    Node* temp=head;
    if(head == NULL) return;
    while(temp->next != head){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data;
    cout<<endl;
}

int main(){
    Node* node1= new Node(1);
    Node* head= node1;
    Node* tail= node1;
    InsertAtTail(head,tail,2);
    InsertAtTail(head,tail,3);
    InsertAtTail(head,tail,4);
    InsertAtTail(head,tail,5);
    InsertAtTail(head,tail,6);
    print(head,tail);
    Node* head2=Split(head);
    print(head,tail);
    print(head2,tail);
}