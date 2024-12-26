#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    //constructor
    Node(int data){
        this->data=data;
        this->prev=NULL;
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
            this->prev=NULL;
        }
    }
};

//to insert node at start
void InsertAtStart(Node* &head,Node* &tail,int data){

    //if no node in LL
    if(head==NULL){

        //make a new node
        Node* temp= new Node(data);

        //both pointers on the new node
        head=temp;
        tail=temp;
    }else{

        //make a new node
        Node* temp= new Node(data);

        //new node's next will be head
        temp->next=head;

        //head's previous will be new node
        head->prev=temp;

        //head pointer moves to new node
        head=temp;
    }
}

void InsertAtTail(Node* &head,Node* &tail,int data){

    //if no node in LL
    if(tail==NULL){

        //make a new node
        Node* temp=new Node(data);

        //both pointers on the new node
        head=temp;
        tail=temp;
    }else{

        //make a new node
        Node* temp=new Node(data);

        //new node's previous will be tail
        temp->prev=tail;

        //tail's next will be new new node
        tail->next=temp;

        //tail moves ahead
        tail=temp;
    }
}

void InsertInMiddle(Node* &head,Node* &tail,int pos,int data){

    //if to insert at start
    if(pos==1){
        InsertAtStart(head,tail,data);
        return;
    }

    //pointer starting at head
    Node* temp=head;
    int count=1;

    //iterating just a node before position
    while(count<pos-1){
        temp=temp->next;
        count++;
    }

    //insert at end
    if(temp->next==NULL){
        InsertAtTail(head,tail,data);
        return;
    }

    //make a new node
    Node* NodeToInsert=new Node(data);

    //new node's next will be previous node's  next
    NodeToInsert->next=temp->next;

    //new node's previous will be previous node 
    NodeToInsert->prev=temp;

    //next node's previous will be new node
    temp->next->prev=NodeToInsert;

    //previous node next will be new node
    temp->next=NodeToInsert;
}

void Delete(Node* &head, Node* &tail,int pos){

    //if at start
    if(pos==1){

        //pointer
        Node* temp=head;

        //move head ahead
        head=temp->next;

        //now the node to be deleted's next will be NULL
        temp->next=NULL;

        //now the node to be deleted's previous will be NULL
        head->prev=NULL;

        //delete the node
        delete temp;
    }
    else{

        //pointer
        Node* curr=head;
        Node* previ=NULL;
        int count=1;

        //iterate before the position
        while(count<pos){

            //previous same as curr
            previ=curr;

            //curr move ahead
            curr=curr->next;

            //increase counter
            count++;
        }

        //now make the previous node next as current node's next
        previ->next=curr->next;

        //the next node previous will be the previous node
        curr->next->prev=previ;

        //current node next will pe NULL
        curr->next=NULL;

        //current node previous will pe NULL
        curr->prev=NULL;

        //delete current
        delete curr;
    }
}

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main(){
    Node* node1= new Node(10);

    Node* head= node1;
    Node* tail= node1;
    InsertAtStart(head,tail,2);
    InsertAtStart(head,tail,1);
    InsertAtTail(head,tail,5);
    InsertAtTail(head,tail,6);
    InsertInMiddle(head,tail,2,3);
    InsertInMiddle(head,tail,1,4);
    Delete(head,tail,2);
    print(head);
}