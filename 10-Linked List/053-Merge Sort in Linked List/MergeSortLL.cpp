/*MergeSort Linked List
For a given Singly Linked List of integers, sort the list using the 'Merge Sort' algorithm.
https://www.naukri.com/code360/problems/mergesort-linked-list_630514*/
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

Node* getmid(Node* head){

    //slow pointer
    Node* slow=head;

    //fast pointer
    Node* fast=head->next;

    //if fast reaches the last node meaning the slow pointer will reach the middle part
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}

Node* merge(Node* left, Node* right){
    if(left==NULL){
        return right;
    }
    if(right==NULL){
        return left;
    }
    Node* ans=new Node(-1);
    Node* temp=ans;
    while(left!=NULL && right!=NULL){

        //if the right LL is smaller than left LL
        if(left->data<right->data){

            //add left data to new LL
            temp->next=left;

            //iterate ahead
            temp=left;

            //iterate ahead in left LL
            left=left->next;
        }else{

            //add right data to new LL
            temp->next=right;

            //iterate ahead
            temp=right;

            //iterate ahead in right LL
            right=right->next;
        }
    }

    //if the left LL is not null
    while(left!=NULL){

        //add left data to new LL
        temp->next=left;

        //iterate ahead
        temp=left;

        //iterate ahead in left LL
        left=left->next;
    }

    //if the right LL is not null
    while(right!=NULL){

        //add right data to new LL
        temp->next=right;

        //iterate ahead
        temp=right;

        //iterate ahead in right LL
        right=right->next;
    }
    ans=ans->next;
    return ans;
}

Node * mergesort(Node* head){

    //base case
    if(head==NULL || head->next==NULL){
        return head;
    }

    //middle node
    Node* middle=getmid(head);

    //left LL
    Node* left=head;

    //right LL
    Node* right=middle->next;

    //separate both LL
    middle->next=NULL;

    //recursivly call for left LL
    left=mergesort(left);

    //recursivly call for right LL
    right=mergesort(right);

    Node* result=merge(left,right);
    return result;
}

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

void print(Node* head){
    Node* temp= head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    Node* node1= new Node(5);
    Node* head=node1;
    Node* tail=node1;
    InsertAtTail(head,tail,3);
    InsertAtTail(head,tail,2);
    InsertAtTail(head,tail,4);
    InsertAtTail(head,tail,1);
    print(head);
    head=mergesort(head);
    print(head); 
    return 0;
}