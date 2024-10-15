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

Node * Split(Node* head){
    
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

void print(Node* &head,Node* &tail){
    Node* temp=head;
    while(temp->next != head){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data;
}

int main(){
    Node* node1= new Node(1);
    Node* head= node1;
    Node* tail= node1;
    InsertAtTail(head,tail,2);
    InsertAtTail(head,tail,3);
    InsertAtTail(head,tail,4);
    print(head,tail);
}