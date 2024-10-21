#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* arb;

    Node(int data){
        this->data=data;
        this->next=NULL;
        this->arb=NULL;
    }
};

void print(Node* &head){
    Node* temp= head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void InsertAtTail(Node* &head,Node* &tail,int d){
    Node* temp=new Node(d);
    if(head==NULL){
        head=temp;
        tail=temp;
        return;
    }else{
        tail->next=temp;
        tail=temp;
    }
}

Node* Clone(Node* head){
    //clone normal Linked List
    Node* cloneHead=NULL;
    Node* cloneTail=NULL;

    Node* temp=head;
    while(temp!=NULL){
        InsertAtTail(cloneHead,cloneTail,temp->data);
        temp=temp->next;
    }
    //adding clone nodes in between original nodes
    Node* orginalNode=head;
    Node* cloneNode=cloneHead;
    while(orginalNode!=NULL && cloneNode!=NULL){
        Node* next=orginalNode->next;
        orginalNode->next=cloneNode;
        orginalNode=next;

        next=cloneNode->next;
        cloneNode->next=orginalNode;
        cloneNode=next;
    }

    //random pointer copy
    temp=head;
    while(temp!=NULL){
        if(temp->next!=NULL){
            if(temp->arb!=NULL){
                temp->next->arb=temp->arb->next;
            }else{
                temp->next=temp->arb;
            }
            temp=temp->next->next;
        }
    }

    //revert changes
    orginalNode=head;
    cloneNode=cloneHead;
    while(orginalNode!=NULL && cloneNode!=NULL){
        orginalNode->next=cloneNode->next;
        orginalNode=orginalNode->next;
        if(orginalNode!=NULL){
            cloneNode->next=orginalNode->next;
        }
        cloneNode=cloneNode->next;
    }
    return cloneHead;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    
    InsertAtTail(head, tail, 1);
    InsertAtTail(head, tail, 2);
    InsertAtTail(head, tail, 3);
    InsertAtTail(head, tail, 4);
    
    head->arb = head->next->next;       
    head->next->arb = head;              
    head->next->next->arb = head->next->next->next; 
    head->next->next->next->arb = head->next;      

    print(head);
    Node* clonedHead = Clone(head);
    print(clonedHead);
    return 0;
}
