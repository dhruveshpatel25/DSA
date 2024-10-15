#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }

    ~Node(){
        int value = this->data;
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
    }
};

void InsertAtStart(Node* &head,int d){
    Node* temp= new Node(d);
    temp->next=head;
    head=temp;
}

void InsertAtTail(Node* &tail,int d){
    Node* temp=new Node(d);
    tail->next=temp;
    tail=temp;
}

void InsertInMiddle(Node* &head,Node* &tail,int pos,int d){

    if(pos==1){ //insert at start
        InsertAtStart(head,d);
        return;
    }
    Node* temp= head;  
    int count=1;
    while(count<pos-1){
        temp=temp->next;
        count++;
    }

    if(temp->next==NULL){ //inset at end
        InsertAtTail(tail,d);
        return;
    }

    Node* NodeToInsert= new Node(d);
    NodeToInsert->next = temp->next;
    temp->next=NodeToInsert;
}

void Delete(Node* &head,Node* &tail,int pos){
    if(pos==1){
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }else{
        Node* curr=head;
        Node* prev=NULL;
        int count=1;
        while(count<pos){
            prev=curr;
            curr=curr->next;
            count++;
        }
        prev->next=curr->next;
        curr->next=NULL;
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