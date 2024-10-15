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

void InsertAtStart(Node* &head,Node* &tail,int data){
    if(head==NULL){
        Node* temp=new Node(data);
        head=temp;
        temp->next=temp;
    }else{
        Node* temp=new Node(data);
        temp->next=head;
        tail->next=temp;
        head=temp;
    }
}

void InsertAtTail(Node* &head, Node* &tail, int data){
    if(tail==NULL){
        Node* temp=new Node(data);
        tail=temp;
        temp->next=temp;
    }else{
        Node* temp=new Node(data);
        tail->next=temp;
        temp->next=head;
        tail=temp;
    }
}

void InsertInMiddle(Node* &head, Node* &tail,int pos, int data){
    if(pos==1){
        InsertAtStart(head,tail,data);
    }
    Node* temp=head;
    int count=1;
    while(count<pos-1){
        temp=temp->next;
        count++;
    }
    if(temp->next == head){
        InsertAtTail(head,tail,data);
    }
    Node* newNode=new Node(data);
    newNode->next=temp->next;
    temp->next=newNode;
    temp=newNode;
}

void Delete(Node* &head,Node* &tail,int pos){
    if(pos==1){
        Node* temp=head;
        tail->next=temp->next;
        head=temp->next;
        temp->next=NULL;
        delete temp;
    }
    Node* curr=head;
    Node* prev=tail;
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