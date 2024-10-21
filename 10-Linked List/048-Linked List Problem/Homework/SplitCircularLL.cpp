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

Node* Split(Node* head){
    if(head == NULL || head->next==head){
        return head;
    }
    Node* slow = head;
    Node* fast = head;
    while(fast->next!=head /*for odd length*/&& fast->next->next!=head/*for even length*/){
        slow=slow->next;
        fast=fast->next->next;
    }
    //adjusting for even length
    if(fast->next->next==head){
        fast=fast->next;
    }

    Node* head2=slow->next;
    fast->next=head2;
    slow->next=head;    
    return head2;
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
    if(head == NULL) return;
    while(temp->next != head){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data;
    cout<<endl;
}

int main(){
    Node* node1= new Node(1);
    Node* head= node1;
    Node* tail= node1;
    InsertAtTail(head,tail,2);
    InsertAtTail(head,tail,3);
    InsertAtTail(head,tail,4);
    InsertAtTail(head,tail,5);
    InsertAtTail(head,tail,6);
    print(head,tail);
    Node* head2=Split(head);
    print(head,tail);
    print(head2,tail);
}