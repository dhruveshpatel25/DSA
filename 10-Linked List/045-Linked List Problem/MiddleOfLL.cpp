/*Middle Of Linked List
Given a singly linked list of 'N' nodes. The objective is to determine the middle node of a singly linked list. However, if the list has an even number of nodes, we return the second middle node.

Note:
1. If the list is empty, the function immediately returns None because there is no middle node to find.
2. If the list has only one node, then the only node in the list is trivially the middle node, and the function returns that node.
https://www.naukri.com/code360/problems/middle-of-linked-list_973250*/
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

//to find length of LL
int getlength(Node* head){
    int len=0;
    while(head!=NULL){
        len++;
        head=head->next;
    }
    return len;
}

Node *Middle(Node* &head){
    int len=getlength(head);
    int ans= (len/2);
    Node* temp = head;
    int count=0;

    //move temp till u get middle
    while(count<ans){
        temp=temp->next;
        count++;
    }
    return temp;
}


int main(){
    Node* node1=new Node(1);
    int ans;
    Node* head=node1;
    Node* tail=node1;
    InsertAtTail(tail,2);
    InsertAtTail(tail,3);
    InsertAtTail(tail,4);
    InsertAtTail(tail,5);
    InsertAtTail(tail,6);
    Middle(head);
    Node* middleNode = Middle(head);
    if (middleNode != NULL) {
        cout << "Middle node value: " << middleNode->data << endl;
    } else {
        cout << "List is empty." << endl;
    }
}