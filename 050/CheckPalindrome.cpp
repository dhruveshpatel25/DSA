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

Node* getmid(Node* head){
    Node* slow=head;
    Node* fast=head->next;
    while(fast!=NULL && slow!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}

Node* reverse(Node* head){
    Node* curr=head;
    Node* prev=NULL;
    Node* forward=NULL;
    while(curr!=NULL){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    return prev;
}

bool Palindrome(Node* head){
    if(head->next==NULL){
        return true;
    }
    Node* middle = getmid(head);
    Node* temp=middle->next;
    middle->next=reverse(temp);
    Node* head1=head;
    Node* head2=middle->next;
    while(head2!=NULL){
        if(head1->data!=head2->data){
            return false;
        }
        head1=head1->next;
        head2=head2->next;
    }
    temp=middle->next;
    middle->next=reverse(temp);
    return true;
}

int main(){
    Node* node1= new Node(1);
    Node* head=node1;
    Node* tail=node1;
    InsertAtTail(tail,0);
    InsertAtTail(tail,2);
    InsertAtTail(tail,0);
    InsertAtTail(tail,1);
    print(head);
    bool ans=Palindrome(head); 
    cout<<ans;
}