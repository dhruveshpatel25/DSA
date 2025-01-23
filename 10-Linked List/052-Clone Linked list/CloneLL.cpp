/*Clone List with Next and Random
You are given a special linked list with n nodes where each node has two pointers a next pointer that points to the next node of the singly linked list, and a random pointer that points to the random node of the linked list.
Construct a copy of this linked list. The copy should consist of the same number of new nodes, where each new node has the value corresponding to its original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list, such that it also represent the same list state. None of the pointers in the new list should point to nodes in the original list.
Return the head of the copied linked list.

Examples:
Input: head = [[1, 3], [3, 3], [5, NULL], [9, 3]] 
Output: head = [[1, 3], [3, 3], [5, NULL], [9, 3]] 
Explanation: 
Node 1 points to Node 2 as its NEXT and Node 3 as its RANDOM.
Node 2 points to Node 3 as its NEXT and Node 3 as its RANDOM.
Node 3 points to Node 4 as its NEXT and NULL as its RANDOM.
Node 4 points to NULL as its NEXT and Node 3 as its RANDOM.

Input: head = [[1, 3], [2, 1], [3, 5], [4, 3], [5, 2]]
Output: head = [[1, 3], [2, 1], [3, 5], [4, 3], [5, 2]]
Explanation: 
Node 1 points to Node 2 as its NEXT and Node 3 as its RANDOM.
Node 2 points to Node 3 as its NEXT and Node 1 as its RANDOM.
Node 3 points to Node 4 as its NEXT and Node 5 as its RANDOM.
Node 4 points to Node 5 as its NEXT and Node 3 as its RANDOM.
Node 5 points to NULL as its NEXT and Node 2 as its RANDOM.

Input: head = [[7, NULL], [7, NULL]]
Output: head = [[7, NULL], [7, NULL]]
Explanation: 
Node 1 points to Node 2 as its NEXT and NULL as its RANDOM.
Node 2 points to NULL as its NEXT and NULL as its RANDOM.
https://www.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1*/
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* arb;

    //constructor
    Node(int data){
        this->data=data;
        this->next=NULL;
        this->arb=NULL;
    }
};

void print(Node* &head){
    Node* temp= head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
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

Node* Clone(Node* head){

    //clone normal Linked List
    Node* cloneHead=NULL;
    Node* cloneTail=NULL;

    Node* temp=head;
    while(temp!=NULL){
        InsertAtTail(cloneHead,cloneTail,temp->data);
        temp=temp->next;
    }

    //adding clone nodes in between original nodes
    Node* orginalNode=head;
    Node* cloneNode=cloneHead;
    while(orginalNode!=NULL && cloneNode!=NULL){

        //save the original LL's next 
        Node* next=orginalNode->next;

        //now point the original LL to new LL
        orginalNode->next=cloneNode;

        //Move originalNode to the next original node
        orginalNode=next;

        //save the next of new LL
        next=cloneNode->next;

        //now point the new LL to original
        cloneNode->next=orginalNode;

        //Move cloneNode to the next clone node
        cloneNode=next;
    }

    //random pointer copy
    temp=head;
    while(temp!=NULL){
        if(temp->next!=NULL){
            if(temp->arb!=NULL){

                // Set random pointer for clone
                temp->next->arb=temp->arb->next;
            }else{

                // No random pointer to copy
                temp->next=temp->arb;
            }

            // Move to the next original node
            temp=temp->next->next;
        }
    }

    //revert changes
    orginalNode=head;
    cloneNode=cloneHead;
    while(orginalNode!=NULL && cloneNode!=NULL){

        // Restore original list's next pointers
        orginalNode->next=cloneNode->next;

        // Move to the next original node
        orginalNode=orginalNode->next;
        if(orginalNode!=NULL){

            // Restore clone list's next pointers
            cloneNode->next=orginalNode->next;
        }

        // Move to the next clone node
        cloneNode=cloneNode->next;
    }
    return cloneHead;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    
    InsertAtTail(head, tail, 1);
    InsertAtTail(head, tail, 2);
    InsertAtTail(head, tail, 3);
    InsertAtTail(head, tail, 4);
    
    head->arb = head->next->next;       
    head->next->arb = head;              
    head->next->next->arb = head->next->next->next; 
    head->next->next->next->arb = head->next;      

    print(head);
    Node* clonedHead = Clone(head);
    print(clonedHead);
    return 0;
}
