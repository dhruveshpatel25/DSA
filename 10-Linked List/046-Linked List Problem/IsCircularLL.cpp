/*Circularly Linked
You are given the head of a linked list containing integers, You need to find out whether the given linked list is circular or not.

Note :
1. A linked list is said to be circular if it has no node having its next pointer equal to NULL and all the nodes form a circle i.e. the next pointer of last node points to the first node.
2. An empty linked will also be considered as circular.
3. All the integers in the linked list are unique.
4. In the input, the next pointer of a node with i’th integer is linked to the node with data (i+1)’th integer (If (i+1)’th node exists). If there is no such (i+1)’th integer then the next pointer of such node is set to NULL.
https://www.naukri.com/code360/problems/circularly-linked_1070232*/
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

    //if no node return false
    if(head==NULL){
        return false;
    }

    //temp pointer on head
    Node* temp=head->next;

    //iterate temp till last node and check if there is any connection to head
    while(temp!=NULL && temp!=head){
        temp=temp->next;
    }

    //if there is connection to head it is circular
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