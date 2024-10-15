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

Node* addition(Node* head1,Node* head2){
    int carry=0;
    Node* anshead=NULL;
    Node* anstail=NULL;
    while(head1!=NULL || head2!=NULL || carry!=0){
        int val1=0;
        if(head1!=NULL){
            val1=head1->data;
        }
        int val2=0;
        if(head2!=NULL){
            val2=head2->data;
        }

        int sum=carry+val1+val2;
        int digit=sum%10;
        InsertAtTail(anshead,anstail,digit);
        carry=sum/10;
        if(head1!=NULL){
            head1=head1->next;
        }
        if(head2!=NULL){
            head2=head2->next;
        }
    }
    return anshead;
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

Node* sum(Node* head1,Node* head2){
    head1=reverse(head1);
    head2=reverse(head2);

    Node* ans= addition(head1,head2);

    return reverse(ans);
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
    InsertAtTail(head1,tail1,2);
    InsertAtTail(head1,tail1,3);
    InsertAtTail(head1,tail1,4);
    InsertAtTail(head1,tail1,5);
    print(head1);

    Node* node2= new Node(1);
    Node* head2=node2;
    Node* tail2=node2;
    InsertAtTail(head2,tail2,2);
    InsertAtTail(head2,tail2,3);
    InsertAtTail(head2,tail2,4);
    InsertAtTail(head2,tail2,5);
    print(head2);

    Node* ans=sum(head1,head2);
    print(ans);
}