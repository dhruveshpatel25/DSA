/*Reverse List In K Groups
You are given a linked list of 'n' nodes and an integer 'k', where 'k' is less than or equal to 'n'.
Your task is to reverse the order of each group of 'k' consecutive nodes, if 'n' is not divisible by 'k', then the last group of nodes should remain unchanged.
For example, if the linked list is 1->2->3->4->5, and 'k' is 3, we have to reverse the first three elements, and leave the last two elements unchanged. Thus, the final linked list being 3->2->1->4->5.
Implement a function that performs this reversal, and returns the head of the modified linked list.

Example:
Input: 'list' = [1, 2, 3, 4], 'k' = 2
Output: 2 1 4 3
Explanation:
We have to reverse the given list 'k' at a time, which is 2 in this case. So we reverse the first 2 elements then the next 2 elements, giving us 2->1->4->3.

Note:
All the node values will be distinct.
https://www.naukri.com/code360/problems/reverse-list-in-k-groups_983644*/
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

Node* ReverseKOrder(Node* &head,int k){
    if(head==NULL){
        return NULL;
    }

    //pointers
    Node* forward=NULL;
    Node* prev=NULL;
    Node* curr=head;
    int count=0;

    //iterate till the k
    while(curr!=NULL && count<k){

        //move forward ahead of current
        forward=curr->next;

        //now make the next of current to previous node
        curr->next=prev;

        //move previous pointer ahead
        prev=curr;

        //move current pointer ahead
        curr=forward;

        //increase counter
        count++;
    }

    if(forward!=NULL){

        //recursivly calling for k groups
        head->next= ReverseKOrder(forward,k);
    }
    return prev;
}



void InsertAtTail(Node* &tail,int d){

    //create a new node
    Node* temp=new Node(d);

    //add the new node at last
    tail->next=temp;

    //make the tail pointer at the new node
    tail=temp;
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
    Node* node1=new Node(1);
    Node* head=node1;
    Node* tail=node1;
    InsertAtTail(tail,2);
    InsertAtTail(tail,3);
    InsertAtTail(tail,4);
    InsertAtTail(tail,5);
    InsertAtTail(tail,6);
    print(head);
    head= ReverseKOrder(head,4);
    print(head);
}