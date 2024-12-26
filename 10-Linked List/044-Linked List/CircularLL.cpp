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

//to insert node at start
void InsertAtStart(Node* &head,Node* &tail,int data){

    //if no node in LL
    if(head==NULL){

        //make a new node
        Node* temp=new Node(data);

        //pointer at head
        head=temp;

        //to make it circular
        temp->next=temp;
    }else{

        //make a new node
        Node* temp=new Node(data);

        //new node's next will be head
        temp->next=head;

        //last node's next will be new node to make it circular
        tail->next=temp;

        //head pointer on new node
        head=temp;
    }
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

void InsertInMiddle(Node* &head, Node* &tail,int pos, int data){

    //insert at start
    if(pos==1){
        InsertAtStart(head,tail,data);
    }

    //pointer starting at head
    Node* temp=head;
    int count=1;

    //iterating just a node before position
    while(count<pos-1){
        temp=temp->next;
        count++;
    }

    //insert at tail
    if(temp->next == head){
        InsertAtTail(head,tail,data);
    }

    //make a new node
    Node* newNode=new Node(data);

    //new node's next would be same as its previous node's next
    newNode->next=temp->next;

    //now the previous node's next will bw new node
    temp->next=newNode;
}

void Delete(Node* &head,Node* &tail,int pos){

    //if at start
    if(pos==1){

        //pointer
        Node* temp=head;

        //last node's next will be the head's next node
        tail->next=temp->next;

        //move head ahead
        head=temp->next;

        //now the node to be deleted's next will be NULL
        temp->next=NULL;

        //delete the node
        delete temp;
    }

    //pointer
    Node* curr=head;
    Node* prev=tail;
    int count=1;

    //iterate before the position
    while(count<pos){

        //previous same as curr
        prev=curr;

        //curr move ahead
        curr=curr->next;

        //increase counter
        count++;
    }

    //now make the previous node next as current node's next
    prev->next=curr->next;

    //current node's next is NULL
    curr->next=NULL;

    //delete current
    delete curr;
}

void print(Node* &head,Node* &tail){
    Node* temp=head;
    while(temp->next != head){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data;
}

int main(){
    Node* node1= new Node(10);
    Node* head= node1;
    Node* tail= node1;
    InsertAtStart(head,tail,4);
    InsertAtStart(head,tail,5);
    InsertAtTail(head,tail,6);
    InsertAtTail(head,tail,7);
    InsertInMiddle(head,tail,4,3);
    Delete(head,tail,2);
    Delete(head,tail,3);
    print(head,tail);
}