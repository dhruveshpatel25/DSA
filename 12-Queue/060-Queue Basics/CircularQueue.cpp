/* Circular Queue
You will be given ‘Q’ queries. You need to implement a circular queue according to those queries. Each query will belong to one of these two types:

1 ‘X’: Enqueue element ‘X’ into the end of the nth queue. Returns true if the element is enqueued, otherwise false.
2: Dequeue the element at the front of the nth queue. Returns -1 if the queue is empty, otherwise, returns the dequeued element.
Note:
Enqueue means adding an element to the end of the queue, while Dequeue means removing the element from the front of the queue.
https://www.naukri.com/code360/problems/circular-queue_1170058*/
#include<iostream>
using namespace std;

class Queue{
    int *arr;
    int front;
    int rear;
    int size;

    public:
    Queue(){
        int size=10000;
        arr=new int[size];
        front=-1;
        rear=-1;
    }

    void enqueue(int data){

        //check overflow 
        if((front==0 && rear==size-1) || (rear==(front-1)%(size-1))){
            cout<<"Queue is Full"<<endl;
        }

        //when queue is empty
        else if(front==-1){
            front=rear=0;
            arr[rear]=data;
        }

        //when there is space in front part of queue and rear pointer is at end
        else if(rear==size-1 && front!=0){
            rear=0;
            arr[rear]=data;
        }
        
        //normal case
        else{
            rear++;
            arr[rear]=data;
        }
    }

    int dequeue(){
        //when queue is empty
        if(front==-1){
            return -1;
        }
        int ans = arr[front];
        arr[front]=-1;

        //single element in queue
        if(front==rear){
            front=rear=-1;
        }
        //when front pointer reaches the end of queue
        else if(front==size-1){
            front=0;
        }

        //normal case
        else{
            front++;
        }
        return ans;
    }
};

int main() {
    Queue myQueue;

    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);

    cout << "Dequeued: " << myQueue.dequeue() << endl;
    cout << "Dequeued: " << myQueue.dequeue() << endl;

    myQueue.enqueue(40);
    myQueue.enqueue(50);

    cout << "Dequeued: " << myQueue.dequeue() << endl;
    cout << "Dequeued: " << myQueue.dequeue() << endl;

    return 0;
}
