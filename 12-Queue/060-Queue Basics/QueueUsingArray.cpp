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
#include<queue>
using namespace std;

class Queue{
    int *arr;
    int qfront;
    int rear;
    int size;

    public:

    Queue(){
        int size=10000;
        arr=new int[size];
        qfront=0;
        rear=0;
    }

    void enqueue(int data){

        //check overflow
        if(rear==size){
            cout<<"Queue is Full"<<endl;
        }else{
            arr[rear]=data;
            rear++;
        }
    }

    int dequeue(){

        //check unerflow condition
        if(qfront==rear){
            cout<<"Queue is Empty";
        }else{
            int ans=arr[qfront];
            arr[qfront]=-1;
            qfront++;
            
            //to avoid wastage of spacce
            if(qfront==rear){
                qfront=0;
                rear=0;
            }
            return ans;
        }
    }

// return the front value of queue
    int front(){
        if(qfront==rear){
            return -1;
        }
        return arr[qfront];
    }

    bool IsEmpty(){
        if(qfront==rear){
            return true;
        }else{
            return false;
        }
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.front() << endl;
    cout << "Dequeued element: " << q.dequeue() << endl;
    cout << "Front element after dequeue: " << q.front() << endl;

    return 0;
}