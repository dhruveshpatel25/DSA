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
        if((front==0 && rear==size-1) || (rear==(front-1)%(size-1))){
            cout<<"Queue is Full"<<endl;
        }
        else if(front==-1){
            front=rear=0;
            arr[rear]=data;
        }
        else if(rear==size-1 && front!=0){
            rear=0;
            arr[rear]=data;
        }else{
            rear++;
            arr[rear]=data;
        }
    }

    int dequeue(){
        if(front==-1){
            return -1;
        }
        int ans = arr[front];
        arr[front]=-1;
        if(front==rear){
            front=rear=-1;
        }
        else if(front==size-1){
            front=0;
        }
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
