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

Node* ReverseKOrder(Node* &head,int k){
    if(head==NULL){
        return NULL;
    }
    Node* forward=NULL;
    Node* prev=NULL;
    Node* curr=head;
    int count=0;
    while(curr!=NULL && count<k){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
        count++;
    }

    if(forward!=NULL){
        head->next= ReverseKOrder(forward,k);
    }
    return prev;
}



void InsertAtTail(Node* &tail,int d){

    //create a new node
    Node* temp=new Node(d);

    //add the new node at last
    tail->next=temp;

    //make the tail pointer at the new node
    tail=temp;
}

void print(Node* head){
    Node* temp= head;
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
    InsertAtTail(tail,5);
    InsertAtTail(tail,6);
    print(head);
    head= ReverseKOrder(head,4);
    print(head);
}