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

Node * RemoveDuplicateSorted(Node* &head){
    if(head==NULL){
        return NULL;
    }
    Node * curr=head;
    while(curr!=NULL){
        if(curr->next!=NULL && curr->data==curr->next->data){
            Node* temp = curr->next->next;
            Node *todelete = curr->next;
            delete(todelete);
            curr->next = temp;
        }
        else{
            curr=curr->next;
        }
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
    Node* node1= new Node(1);
    Node* head=node1;
    Node* tail=node1;
    InsertAtTail(tail,2);
    InsertAtTail(tail,2);
    InsertAtTail(tail,3);
    print(head);
    RemoveDuplicateSorted(head);
    print(head); 
}