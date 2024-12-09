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

Node* DetectCycle(Node* head){

    //if there in no LL
    if(head==NULL){
        return NULL;
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
            return NULL;
        }

        //when slow reaches fast at same node means there is cycle
        if(slow==fast){
            return fast;
        }
    }
}

Node* getStarting(Node* head){

    //if there in no LL
    if(head==NULL){
        return NULL;
    }

    //fast node from the function
    Node* intersection=DetectCycle(head);

    //placing the slow at head node
    Node* slow=head;

    //till slow and intersection meets
    while(slow!=intersection){

        //iterate the slow pointer
        slow=slow->next;

        //iterate the fast pointer
        intersection=intersection->next;
    }

    return intersection;
}

int main() {
    Node* head = NULL;  // Initialize the head pointer
    Node* tail = NULL;  // Initialize the tail pointer

    // Insert nodes into the linked list
    InsertAtTail(head, tail, 1);
    head = tail;  // Set head after the first insertion
    InsertAtTail(head, tail, 2);
    InsertAtTail(head, tail, 3);
    InsertAtTail(head, tail, 4);

    // Intentionally create a loop for testing
    tail->next = head->next; // Point the last node to the second node to create a cycle

    // Detect cycle
    Node* intersection = DetectCycle(head);
    if (intersection != NULL) {
        cout << "Cycle detected at node with value: " << intersection->data << endl;

        // Find the starting point of the cycle
        Node* cycleStart = getStarting(head);
        cout << "The starting node of the cycle is: " << cycleStart->data << endl;
    } else {
        cout << "No cycle detected." << endl;
    }

    return 0;
}
