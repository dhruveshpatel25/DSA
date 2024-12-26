#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    //constructor
    Node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
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

        //head pointer at new node
        head=temp;

        //double circular LL
        temp->next=temp;
        temp->prev=temp;
    }else{

        //make a new node
        Node* temp=new Node(data);

        //head node previous will be new node
        head->prev=temp;

        //new node's next will be head
        temp->next=head;

        //new node previous will pe tail(circular LL)
        temp->prev=tail;

        //tail node next will be new node(circular LL)
        tail->next=temp;

        //head pointer at new node
        head=temp;
    }
}

void InsertAtTail(Node* &head,Node* &tail,int data){

    //if no node in LL
    if(tail==NULL){

        //make a new node
        Node* temp=new Node(data);

        //tail at new node
        tail=temp;

        //double circular LL
        temp->next=temp;
        temp->prev=temp;
    }else{

        //make a new node
        Node* temp=new Node(data);

        //new node previous at tail(circular)
        temp->prev=tail;

        //new node next will be head(circular)
        temp->next=tail->next;

        //tail next will be new node
        tail->next=temp;

        //tail pointer on new node
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

    //new node next will be previous node next
    NodeToInsert->next=temp->next;

    //new node next will be previous node
    NodeToInsert->prev=temp;

    //previous node next will be new node
    temp->next=NodeToInsert;

    //next node previous will be new node
    NodeToInsert->next->prev=NodeToInsert;
}

void Delete(Node* &head, Node* &tail,int pos){

    //if at start
    if(pos==1){

        //pointer
        Node* temp=head;

        //head pointer shifting
        head=temp->next;

        //isolating temp node
        temp->next=NULL;
        temp->prev=NULL;

        //circular LL
        head->prev=tail;
        tail->next=head;
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

        //previous node next will be deleted node next
        previ->next=curr->next;

        //next node previous will be previous node
        curr->next->prev=previ;

        //deleted node next will be NULL
        curr->next=NULL;
        delete curr;
    }
}

void print(Node* &head){
    Node* temp = head;
    while(temp->next!= head){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data;
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
    Delete(head,tail,7);
    print(head);
}