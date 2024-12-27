/*Merge Two Sorted Linked Lists
You are given two sorted linked lists. You have to merge them to produce a combined sorted linked list. You need to return the head of the final linked list.

Note:
The given linked lists may or may not be null.

For example:
If the first list is: 1 -> 4 -> 5 -> NULL and the second list is: 2 -> 3 -> 5 -> NULL
The final list would be: 1 -> 2 -> 3 -> 4 -> 5 -> 5 -> NULL
https://www.naukri.com/code360/problems/merge-two-sorted-linked-lists_800332*/
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

Node * Merge(Node* &head1,Node* &head2){

    //if only 2nd LL exist
    if(head1==NULL){
        return head2;
    }

    //if only 1st LL exist
    if(head2==NULL){
        return head1;
    }

    //new LL
    Node* mergedhead=NULL;

    //if 1st LL smaller
    if(head1->data<head2->data){

        //move pointer on head1
        mergedhead=head1;

        //move the head1 on next node
        head1=head1->next;
    }else{

        //move pointer on head2
        mergedhead=head2;

        //move the head2 on next node
        head2=head2->next;
    }

    //now for other node
    Node* curr=mergedhead;
    while(head1!=NULL && head2!=NULL){

        //if 1st LL smaller
        if(head1->data<=head2->data){

            //move pointer on head1
            curr->next=head1;

            //move the head1 on next node
            head1=head1->next;
        }else{

            //move pointer on head2
            curr->next=head2;

            //move the head2 on next node
            head2=head2->next;
        }

        //move ahead
        curr=curr->next;
    }

    //move ahead
    if(head1!=NULL){
        curr->next=head1;
    }else{
        curr->next=head2;
    }
    return mergedhead;
}

void InsertAtTail(Node* &tail,int d){

    //make a new node
    Node* temp=new Node(d);

    //make the last node's next point towars tail of LL
    tail->next=temp;

    //move tail to new node
    tail=temp;
}

void print(Node* &head){
    Node* temp= head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    Node* node1= new Node(1);
    Node* head1=node1;
    Node* tail1=node1;

    Node* node2=new Node(2);
    Node* head2=node2;
    Node* tail2=node2;
    InsertAtTail(tail1,3);
    InsertAtTail(tail1,5);
    InsertAtTail(tail2,4);
    InsertAtTail(tail2,6);
    print(head1); 
    print(head2);
    head1=Merge(head1,head2);
    print(head1);
}