/* Implement a Queue
Implement a Queue Data Structure specifically to store integer data using a Singly Linked List or an array.

You need to implement the following public functions :

1. Constructor: It initializes the data members as required.
2. enqueue(data): This function should take one argument of type integer. It enqueues the element into the queue.
3. dequeue(): It dequeues/removes the element from the front of the queue and in turn, returns the element being dequeued or removed. In case the queue is empty, it returns -1.
4. front(): It returns the element being kept at the front of the queue. In case the queue is empty, it returns -1.
5. isEmpty(): It returns a boolean value indicating whether the queue is empty or not.

Operations Performed on the Queue :
Query-1(Denoted by an integer 1): Enqueues integer data to the queue.
Query-2(Denoted by an integer 2): Dequeues the data kept at the front of the queue and returns it to the caller, return -1 if no element is present in the queue.
Query-3(Denoted by an integer 3): Fetches and returns the data being kept at the front of the queue but doesn't remove it, unlike the dequeue function, return -1 if no element is present in the queue.
Query-4(Denoted by an integer 4): Returns a boolean value denoting whether the queue is empty or not.
https://www.naukri.com/code360/problems/queue-using-array-or-singly-linked-list_2099908*/
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }

    ~Node(){
        int value = this->data;
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
    }
};

class Queue{
    Node* qfront;
    Node* rear;

    public:
    Queue(){
        qfront=NULL;
        rear=NULL;
    }

    void enqueue(int data){
        Node* temp= new Node(data);

        //when queue gets empty
        if(qfront==rear){
            qfront=rear=temp;
        }
        
        //normal case
        else{
            rear->next=temp;
            rear=temp;
        }
    }

    int dequeue(){
        //check underflow
        if(qfront==NULL){
            return -1;
        }
        Node *temp=qfront;
        int data=qfront->data;
        qfront=qfront->next;

        //when there is single element
        if(qfront==NULL){
            rear=NULL;
        }
        delete temp;
        return data;
    }

    int front(){
        if(qfront==NULL){
            return -1;
        }
        return qfront->data;
    }

    bool IsEmpty(){
        if(qfront==NULL){
            return true;
        }else{
            return true;
        }
    }
};

int main() {
    Queue queue;

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);

    cout << "Dequeued item: " << queue.dequeue() << endl;
    cout << "Dequeued item: " << queue.dequeue() << endl;

    return 0;
}
