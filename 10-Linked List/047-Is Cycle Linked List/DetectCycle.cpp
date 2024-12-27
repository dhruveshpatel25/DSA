/*Detect and Remove Loop
Given a singly linked list, you have to detect the loop and remove the loop from the linked list, if present. You have to make changes in the given linked list itself and return the updated linked list.

Expected Complexity: Try doing it in O(n) time complexity and O(1) space complexity. Here, n is the number of nodes in the linked list.
https://www.naukri.com/code360/problems/interview-shuriken-42-detect-and-remove-loop_241049*/
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int data){

        //data of node
        this->data=data;

        //next of node is marked NULL
        this->next=NULL;
    }

    ~Node(){

        //save the data
        int value = this->data;

        //when it is not last node
        if(this->next!=NULL){

            //deelete the node
            delete next;

            //point the node->next to NULL
            this->next=NULL;
        }
    }
};

void InsertAtTail(Node* &head, Node* &tail, int data){

    //first node
    if(tail==NULL){

        //create a new node
        Node* temp=new Node(data);

        //point the tail at the new node
        tail=temp;
        //temp->next=temp;
    }

    //not the first node
    else{

        //create a new node
        Node* temp=new Node(data);

        //add the new node at last
        tail->next=temp;

        //make the new node->next as NULL
        temp->next=head;

        //make the tail pointer at the new node
        tail=temp;
    }
}

bool DetectCycle(Node* head){

    //if there in no LL
    if(head==NULL){
        return false;
    }

    //fast pointer
    Node* fast=head;

    //slow pointer
    Node* slow=head;

    while(slow!=NULL && fast!=NULL){

        //iterate slow one node at a time
        slow=slow->next;

        //iterate fast two node at a time
        fast=fast->next->next;

        //if fast pointer reaches NULL meaning there is no cycle
        if(fast==NULL){
            return false;
        }

        //when slow reaches fast at same node means there is cycle
        if(slow==fast){
            return true;
        }
    }
}
void print(Node* &head){

    //start from head node
    Node* temp= head;
    while(temp->next!=head){
        cout<<temp->data<<" ";

        //go to next node
        temp=temp->next;
    }

    //last node
    cout<<temp->data;
    cout<<endl;
}

int main() {
    Node* head = NULL;  // Head of the linked list
    Node* tail = NULL;  // Tail of the linked list

    // Insert some nodes
    InsertAtTail(head, tail, 10);
    head = tail;  // Initialize head after the first insertion
    InsertAtTail(head, tail, 20);
    InsertAtTail(head, tail, 30);
    InsertAtTail(head, tail, 40);

    // Print the linked list (it should loop back to head)
    cout << "Initial Circular Linked List:" << endl;
    print(head);

    // Check for a cycle
    if (DetectCycle(head)) {
        cout << "Cycle detected in the linked list." << endl;
    } else {
        cout << "No cycle detected." << endl;
    }

    return 0;
}
