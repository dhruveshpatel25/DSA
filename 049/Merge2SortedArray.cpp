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
};

Node * Merge(Node* &head1,Node* &head2){
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    Node* mergedhead=NULL;
    if(head1->data<head2->data){
        mergedhead=head1;
        head1=head1->next;
    }else{
        mergedhead=head2;
        head2=head2->next;
    }
    Node* curr=mergedhead;
    while(head1!=NULL && head2!=NULL){
        if(head1->data<=head2->data){
            curr->next=head1;
            head1=head1->next;
        }else{
            curr->next=head2;
            head2=head2->next;
        }
        curr=curr->next;
    }
    if(head1!=NULL){
        curr->next=head1;
    }else{
        curr->next=head2;
    }
    return mergedhead;
}

void InsertAtTail(Node* &tail,int d){
    Node* temp=new Node(d);
    tail->next=temp;
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