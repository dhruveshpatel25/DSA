/*Remove Duplicates From an Unsorted Linked List
You are given a linked list of N nodes. Your task is to remove the duplicate nodes from the linked list such that every element in the linked list occurs only once i.e. in case an element occurs more than once, only keep its first occurrence in the list.

For example :
Assuming the linked list is 3 -> 2 -> 3 -> 4 -> 2 -> 3 -> NULL.
Number ‘2’ and ‘3’ occurs more than once. Hence we remove the duplicates and keep only their first occurrence. So, our list becomes : 3 -> 2 -> 4 -> NULL.
https://www.naukri.com/code360/problems/remove-duplicates-from-unsorted-linked-list_1069331*/
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

Node * RemoveDuplicateUnSorted(Node * head){
    if(head == NULL){
        return NULL;
    }

    //pointer on head
    Node* curr= head;

    //iterate till last node
    while(curr!=NULL){

        //pointer on current
        Node* temp=curr;

        //iterate till the last node
        while(temp->next!=NULL){

            //check if any data is same as 'current' node data
            if(curr->data==temp->next->data){

                //go to next of next
                Node* next_next = temp->next->next;

                //go on the node to be deleted
                Node *todelete = temp->next;

                //delete the node
                delete(todelete);

                //make a connection
                temp->next = next_next;
            }
            else{

                //just iterate ahead
                temp=temp->next;
            }
        }

        //just iterate ahead
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