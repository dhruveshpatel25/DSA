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
        if(qfront==rear){
            qfront=rear=temp;
        }else{
            rear->next=temp;
            rear=temp;
        }
    }

    int dequeue(){
        if(qfront==NULL){
            return -1;
        }
        Node *temp=qfront;
        int data=qfront->data;
        qfront=qfront->next;
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
