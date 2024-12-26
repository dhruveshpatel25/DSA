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
void InsertAtStart(Node* &head,int d){

    //make a new node
    Node* temp= new Node(d);

    //make the next node's next point towards head of LL
    temp->next=head;

    //move head to new hode
    head=temp;
}

void InsertAtTail(Node* &tail,int d){

    //make a new node
    Node* temp=new Node(d);

    //make the last node's next point towars tail of LL
    tail->next=temp;

    //move tail to new node
    tail=temp;
}

void InsertInMiddle(Node* &head,Node* &tail,int pos,int d){

    //insert at start
    if(pos==1){ 
        InsertAtStart(head,d);
        return;
    }

    //pointer starting at head
    Node* temp= head;  
    int count=1;

    //iterating just a node before position
    while(count<pos-1){
        temp=temp->next;
        count++;
    }

    //inset at end
    if(temp->next==NULL){ 
        InsertAtTail(tail,d);
        return;
    }

    //make a new node
    Node* NodeToInsert= new Node(d);

    //new node's next would be same as its previous node's next
    NodeToInsert->next = temp->next;

    //now the previous node's next will bw new node
    temp->next=NodeToInsert;
}

void Delete(Node* &head,Node* &tail,int pos){

    //if at start
    if(pos==1){

        //pointer
        Node* temp=head;

        //move head ahead
        head=head->next;

        //now the node to be deleted's next will be NULL
        temp->next=NULL;

        //delete the node
        delete temp;
    }else{

        //pointer
        Node* curr=head;
        Node* prev=NULL;
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
}


void print(Node* &head){
    Node* temp= head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }

}

int main(){
    Node* node1= new Node(10);
    //cout<< node1->data<<endl;
    //cout<< node1->next<<endl;

    Node* head=node1;
    Node* tail=node1;

    InsertAtStart(head,12);
    InsertAtStart(head,15);
    InsertAtTail(tail,14);
    InsertAtTail(tail,16);
    InsertInMiddle(head,tail,3,13);
    InsertInMiddle(head,tail,7,11);
    Delete(head,tail,7);
    print(head); 
}