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

void InsertAtTail(Node* &head,Node* &tail,int d){

    //new node
    Node* temp=new Node(d);

    //if no node
    if(head==NULL){

        //both pointer on new node
        head=temp;
        tail=temp;
        return;
    }else{

        //add the node at end
        tail->next=temp;

        //tail pointer on new node
        tail=temp;
    }
}

Node* addition(Node* head1,Node* head2){
    int carry=0;

    //for new LL
    Node* anshead=NULL;
    Node* anstail=NULL;
    while(head1!=NULL || head2!=NULL || carry!=0){
        int val1=0;

        //1st value
        if(head1!=NULL){
            val1=head1->data;
        }
        int val2=0;

        //2nd value
        if(head2!=NULL){
            val2=head2->data;
        }

        //carry+value1+calue2
        int sum=carry+val1+val2;

        //take the last digit(if more than 10)
        int digit=sum%10;

        //add the digit to new LL
        InsertAtTail(anshead,anstail,digit);

        //add the first part to carry(more than 10)
        carry=sum/10;

        //iterate ahead
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

    //pointers
    Node* curr=head;
    Node* prev=NULL;
    Node* forward=NULL;
    while(curr!=NULL){

        //move forward ahead of current
        forward=curr->next;

        //now make the next of current to previous node
        curr->next=prev;

        //move previous pointer ahead
        prev=curr;

        //move current pointer ahead
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