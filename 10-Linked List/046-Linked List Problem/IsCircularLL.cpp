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

void InsertAtTail(Node* &head, Node* &tail, int data){

    //first node
    if(tail==NULL){

        //create a new node
        Node* temp=new Node(data);

        //point the tail at the new node
        tail=temp;

        //make it circular
        temp->next=temp;
    }//not the first node
    else{

        //create a new node
        Node* temp=new Node(data);

        //add the new node at last
        tail->next=temp;

        //make the new node->next as NULL
        temp->next=head;

        //make the tail pointer at the new node
        tail=temp;
    }
}

bool IsCircular(Node* head){
    if(head==NULL){
        return false;
    }
    Node* temp=head->next;
    while(temp!=NULL && temp!=head){
        temp=temp->next;
    }
    if(temp==head){
        return true;
    }
    return false;
}

void print(Node* &head){
    Node* temp= head;
    while(temp->next!=head){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data;
    cout<<endl;
}

int main(){
    Node* node1=new Node(1);
    Node* head=node1;
    Node* tail=node1;
    InsertAtTail(head,tail,2);
    InsertAtTail(head,tail,3);
    InsertAtTail(head,tail,4);
    InsertAtTail(head,tail,5);
    InsertAtTail(head,tail,6);
    print(head);
    bool result=IsCircular(head);
    cout<<result;
}