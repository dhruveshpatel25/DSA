/*Detect and Remove Loop
Given a singly linked list, you have to detect the loop and remove the loop from the linked list, if present. You have to make changes in the given linked list itself and return the updated linked list.

Expected Complexity: Try doing it in O(n) time complexity and O(1) space complexity. Here, n is the number of nodes in the linked list.
https://www.naukri.com/code360/problems/interview-shuriken-42-detect-and-remove-loop_241049?leftPanelTab=0%3Fsource%3Dyoutube&campaign=YouTube_codestudio_lovebabbar28thjan&utm_source=youtube&utm_medium=affiliate&utm_campaign=YouTube_codestudio_lovebabbar28thjan*/
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

        //head pointer at new node
        head = temp;

        //point the tail at the new node
        tail=temp;
    }

    //not the first node
    else{

        //create a new node
        Node* temp=new Node(data);

        //add the new node at last
        tail->next=temp;

        //make the new node->next as NULL
        temp->next=NULL;

        //make the tail pointer at the new node
        tail=temp;
    }
}

void print(Node* &head){

    //start from head node
    Node* temp= head;
    while(temp->next!=NULL){
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

    while(fast!=NULL && fast->next!=NULL){

        //iterate fast two node at a time
        fast=fast->next->next;

        //if fast pointer reaches NULL meaning there is no cycle
        if(fast==NULL){
            return NULL;
        }

        //iterate slow one node at a time
        slow=slow->next;

        //when slow reaches fast at same node means there is cycle
        if(slow==fast){
            return slow;
        }
    }
    return NULL;
}

Node* getStarting(Node* head){

    //if there in no LL
    if(head==NULL){
        return NULL;
    }

    //fast node from the function
    Node* intersection=DetectCycle(head);

    if(intersection == NULL) {
        return NULL;  // No cycle present
    }

    //placing the slow at head node
    Node* slow=head;

    //till slow and intersection meets
    while(slow!=intersection){

        //iterate the slow pointer
        slow=slow->next;

        //iterate the fast pointer
        intersection=intersection->next;
    }

    return slow;
}

Node* removeLoop(Node* head){
    //if there in no LL
    if(head==NULL){
        return NULL;
    }

    //get the starting loop
    Node* startOfLoop=getStarting(head);

    if (startOfLoop == NULL) {
        return head; // No loop to remove
    }

    //start the loop from the starting point
    Node* temp=startOfLoop;

    //iterate till the temp->next is starting point(meaning the temp will reach the last)
    while(temp->next!=startOfLoop){

        //move forward
        temp=temp->next;
    }

    //make the last node NULL so the cycle is removed
    temp->next=NULL; 
    return head;   
}

int main() {
    Node* head = NULL;  // Initialize the head pointer
    Node* tail = NULL;  // Initialize the tail pointer

    // Insert nodes into the linked list
    InsertAtTail(head, tail, 1);
    InsertAtTail(head, tail, 2);
    InsertAtTail(head, tail, 3);
    InsertAtTail(head, tail, 4);

    // Intentionally create a loop for testing
    tail->next = head->next; // Creating a loop by pointing the last node to the second node

    // Detect and remove the loop
    if (DetectCycle(head)) {
        cout << "Cycle detected in the linked list." << endl;

        // Remove the loop
        head = removeLoop(head);
        cout << "Cycle removed from the linked list." << endl;
    } else {
        cout << "No cycle detected in the linked list." << endl;
    }

    // Print the updated linked list
    cout << "Linked list after removing the loop:" << endl;

    // Print the list to verify that the loop is removed
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}
