/*Reverse Linked List
You are given a Singly Linked List of integers. You need to reverse the Linked List by changing the links between nodes.

Note :
You do not need to print anything, just return the head of the reversed linked list. 
https://www.naukri.com/code360/problems/reverse-linked-list_920513*/
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

void InsertAtTail(Node* &tail,int d){

    //make a new node
    Node* temp=new Node(d);

    //make the last node's next point towars tail of LL
    tail->next=temp;

    //move tail to new node
    tail=temp;
}

Node* Reverse(Node* &head){

    //if no node or single node
    if(head == NULL || head->next == NULL){
        return head;
    }

    //pointers
    Node* prev=NULL;
    Node* curr=head;
    Node* forward=NULL;
    while(curr!=NULL){

        //move forward ahead
        forward=curr->next;

        //now point the current node's next to previous node
        curr->next=prev;

        //now move previous pointer on current node
        prev=curr;

        //now move current pointer on forward node
        curr=forward;

        //now keep the head pointer on previous
        head=prev;
    }
    return head;
}

void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    Node* node1=new Node(1);
    Node* head=node1;
    Node* tail=node1;
    InsertAtTail(tail,2);
    InsertAtTail(tail,3);
    InsertAtTail(tail,4);
    print(head);
    Reverse(head);
    print(head);
}