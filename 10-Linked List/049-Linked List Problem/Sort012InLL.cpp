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

Node * sort(Node * head){
    int zerocount=0;
    int onecount=0;
    int twocount=0;

    Node* temp=head;
    while(temp!=NULL){

        //count 0
        if(temp->data==0){
            zerocount++;
        }

        //count 1
        else if(temp->data==1){
            onecount++;
        }

        //count 2
        else if(temp->data==2){
            twocount++;
        }

        //move ahead
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){

        //if not zero
        if(zerocount!=0){

            //place 0
            temp->data=0;

            //decrease count
            zerocount--;
        }

        //if not one
        else if(onecount!=0){

            //place 1
            temp->data=1;

            //decrease count
            onecount--;
        }

        //if not two
        else if(twocount!=0){

            //place 2
            temp->data=2;

            //decrease count
            twocount--;
        }
        temp=temp->next;
    }
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
    sort(head);
    print(head);
}