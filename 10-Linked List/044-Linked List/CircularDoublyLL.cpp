#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }

    ~Node(){
        int value = this->data;
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
    }
};

void InsertAtStart(Node* &head,Node* &tail,int data){
    if(head==NULL){
        Node* temp=new Node(data);
        head=temp;
        temp->next=temp;
        temp->prev=temp;
    }else{
        Node* temp=new Node(data);
        head->prev=temp;
        temp->next=head;
        temp->prev=tail;
        tail->next=temp;
        head=temp;
    }
}

void InsertAtTail(Node* &head,Node* &tail,int data){
    if(tail==NULL){
        Node* temp=new Node(data);
        tail=temp;
        temp->next=temp;
        temp->prev=temp;
    }else{
        Node* temp=new Node(data);
        temp->prev=tail;
        temp->next=tail->next;
        tail->next=temp;
        tail=temp;
    }
}

void InsertInMiddle(Node* &head,Node* &tail,int pos,int data){
    if(pos==1){
        InsertAtStart(head,tail,data);
        return;
    }
    Node* temp=head;
    int count=1;
    while(count<pos-1){
        temp=temp->next;
        count++;
    }

    if(temp->next==NULL){
        InsertAtTail(head,tail,data);
        return;
    }
    Node* NodeToInsert=new Node(data);
    NodeToInsert->next=temp->next;
    NodeToInsert->prev=temp;
    temp->next=NodeToInsert;
    NodeToInsert=temp;
}

void Delete(Node* &head, Node* &tail,int pos){
    if(pos==1){
        Node* temp=head;
        head=temp->next;
        temp->next=NULL;
        temp->prev=NULL;
        head->prev=tail;
        tail->next=head;
        delete temp;
    }
    else{
        Node* curr=head;
        Node* previ=NULL;
        int count=1;
        while(count<pos){
            previ=curr;
            curr=curr->next;
            count++;
        }
        previ->next=curr->next;
        curr->next->prev=previ;
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