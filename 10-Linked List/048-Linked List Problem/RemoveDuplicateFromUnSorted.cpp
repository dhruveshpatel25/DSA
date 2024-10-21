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

Node * RemoveDuplicateUnSorted(Node * head){
    if(head == NULL){
        return NULL;
    }
    Node* curr= head;
    while(curr!=NULL){
        Node* temp=curr;
        while(temp->next!=NULL){
            if(curr->data==temp->next->data){
                Node* next_next = temp->next->next;
                Node *todelete = temp->next;
                delete(todelete);
                temp->next = next_next;
            }
            else
            {
                temp=temp->next;
            }
        }
        curr=curr->next;
    }
    return head;
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
    Node* node1= new Node(4);
    Node* head=node1;
    Node* tail=node1;
    InsertAtTail(tail,5);
    InsertAtTail(tail,2);
    InsertAtTail(tail,1);
    InsertAtTail(tail,3);
    InsertAtTail(tail,2);
    InsertAtTail(tail,4);
    print(head);
    RemoveDuplicateUnSorted(head);
    print(head); 
}