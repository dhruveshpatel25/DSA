/*Palindrome Linked List
Given a singly linked list of integers. The task is to check if the given linked list is palindrome or not.
Examples:

Input: LinkedList: 1->2->1->1->2->1
Output: true
Explanation: The given linked list is 1->2->1->1->2->1 , which is a palindrome and Hence, the output is true.

Input: LinkedList: 1->2->3->4
Output: false
Explanation: The given linked list is 1->2->3->4, which is not a palindrome and Hence, the output is false.
https://www.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1*/
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

Node* getmid(Node* head){

    //two pointers
    Node* slow=head;
    Node* fast=head->next;

    //iterate till one reaches last node
    while(fast!=NULL && slow!=NULL){

        //2 steps at a time
        fast=fast->next->next;

        //one step at a time
        slow=slow->next;
    }
    return slow;
}

Node* reverse(Node* head){
    Node* curr=head;
    Node* prev=NULL;
    Node* forward=NULL;
    while(curr!=NULL){

        //move forward ahead of current node
        forward=curr->next;

        //now point current to previous
        curr->next=prev;

        //move previous ahead
        prev=curr;

        //move current ahead
        curr=forward;
    }
    return prev;
}

bool Palindrome(Node* head){

    //if only one node
    if(head->next==NULL){
        return true;
    }

    //get middle node
    Node* middle = getmid(head);

    //start after next node
    Node* temp=middle->next;

    //reverse
    middle->next=reverse(temp);

    //pointers are both position
    Node* head1=head;
    Node* head2=middle->next;

    //iterate till last node
    while(head2!=NULL){

        //if not same return false
        if(head1->data!=head2->data){
            return false;
        }

        //if same iterate ahead
        head1=head1->next;
        head2=head2->next;
    }

    //now reverse it back
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