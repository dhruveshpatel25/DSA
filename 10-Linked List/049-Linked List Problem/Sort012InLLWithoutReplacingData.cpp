/*Sort linked list of 0s 1s 2s
Given a linked list of 'N' nodes, where each node has an integer value that can be 0, 1, or 2. You need to sort the linked list in non-decreasing order and the return the head of the sorted list.

Example:
Given linked list is 1 -> 0 -> 2 -> 1 -> 2. 
The sorted list for the given linked list will be 0 -> 1 -> 1 -> 2 -> 2.
https://www.naukri.com/code360/problems/sort-linked-list-of-0s-1s-2s_1071937*/
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

void InsertAtTail1(Node* &tail,Node* temp){

    //store the data next tail
    tail->next=temp;

    //move tail to new node
    tail=temp;
}

Node * SortWithoutReplacing(Node * head){

    //zero LL
    Node* zerohead=new Node(-1);
    Node* zerotail=zerohead;

    //one LL
    Node* onehead=new Node(-1);
    Node* onetail=onehead;

    //two LL
    Node* twohead=new Node(-1);
    Node* twotail=twohead;

    Node* temp=head;
    while(temp!=NULL){
        int value=temp->data;

        //if data 0 add to zero LL
        if(value==0){
            InsertAtTail1(zerotail,temp);
        }

        //if data 1 add to one LL
        else if(value==1){
            InsertAtTail1(onetail,temp);
        }

        //if data 2 add to two LL
        else if(value==2){
            InsertAtTail1(twotail,temp);
        }
        temp=temp->next;
    }

    //zero LL connection to one LL
    if(onehead->next!=NULL){
        zerotail->next = onehead->next;
    }
    
    //if no one LL exist
    else{
        zerotail->next= twohead->next;
    }

    //now connect one LL to two LL
    onetail->next=twohead->next;
    twotail->next=NULL;

    //now head pointer on start of LL
    head=zerohead->next;

    //delete all pointer
    delete zerohead;
    delete onehead;
    delete twohead;

    return head;
}

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

int main(){
    Node* node1= new Node(1);
    Node* head=node1;
    Node* tail=node1;
    InsertAtTail(tail,0);
    InsertAtTail(tail,2);
    InsertAtTail(tail,1);
    InsertAtTail(tail,2);
    print(head); 
    head=SortWithoutReplacing(head);
    print(head);
}