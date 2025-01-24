/* Implement Deque
Problem statement
Design a data structure to implement deque of size ‘N’. It should support the following operations:
pushFront(X): Inserts an element X in the front of the deque. Returns true if the element is inserted, otherwise false.
pushRear(X): Inserts an element X in the back of the deque. Returns true if the element is inserted, otherwise false.
popFront(): Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
popRear(): Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
getFront(): Returns the first element of the deque. If the deque is empty, it returns -1.
getRear(): Returns the last element of the deque. If the deque is empty, it returns -1.
isEmpty(): Returns true if the deque is empty, otherwise false.
isFull(): Returns true if the deque is full, otherwise false.

Following types of queries denote these operations:
Type 1: for pushFront(X) operation.
Type 2: for pushRear(X) operation.
Type 3: for popFront() operation.
Type 4: for popRear() operation.
Type 5: for getFront() operation.
Type 6: for getRear() operation.
Type 7: for isEmpty() operation.
Type 8: for isFull() operation.
https://www.naukri.com/code360/problems/deque_1170059*/
#include<iostream>
#include<queue>
using namespace std;

class DEQueue{
    int *arr;
    int front;
    int rear;
    int size;

    public:
    DEQueue(){
        size=1000;
        arr=new int[size];
        front=rear=-1;
    }

    void PushFront(int data){

        //check overflow
        if((front==0 && rear==size-1) || (front !=0 && rear==(front-1)%(size-1))){
            cout<<"Queue is Full"<<endl;
        }

        //when queue is empty
        else if(front==-1){
            front=rear=0;
        }

        //when queue is at 0th index
        else if(front==0 && rear != size-1){
            front=size-1;
        }

        //normal case
        else{
            front--;
        }
        arr[front]=data;
    }

    void PushBack(int data){

        //check overflow
        if((front==0 && rear==size-1) || (front !=0 && rear==(front-1)%(size-1))){
            cout<<"Queue is Full"<<endl;
        }

        //when queue is empty
        else if(front==-1){
            front=rear=0;
        }

        //when rear is at last index and the queue is not full
        else if(rear==size-1 && front!=0){
            rear=0;
        }

        //normal case
        else{
            rear++;
        }
        arr[rear]=data;
    }

    int PopFront(){

        //when queue is empty
        if(front==-1){
            return -1;
        }
        int ans=arr[front];
        arr[front]=-1;

        //when only single element was present
        if(front==rear){
            front=rear=-1;
        }

        //when elements are present in start of queue
        else if(front==size-1){
            front=0;
        }

        //normal case
        else{
            front++;
        }
        return ans;
    }

    int PopBack(){

        //when queue is empty
        if(front==-1){
            return -1;
        }
        int ans=arr[rear];
        arr[rear]=-1;

        //when only single element was present
        if(front==rear){
            front=rear=-1;
        }

        //when elements are present in the last part of queue
        else if(rear==0){
            rear=size-1;
        }

        //normal case
        else{
            rear--;
        }
        return ans;
    }

    bool IsEmpty(){
        if(front==-1){
            return true;
        }else{
            return false;
        }
    }

    int getFront(){
        if(IsEmpty()){
            return -1;
        }
        return arr[front];
    }

    int getBack(){
        if(IsEmpty()){
            return -1;
        }
        return arr[rear];
    }
};

int main() {
    DEQueue myDeque;
    myDeque.PushFront(10);
    myDeque.PushBack(20);
    myDeque.PushFront(5);
    myDeque.PushBack(30);

    cout << "Popped from front: " << myDeque.PopFront() << endl;
    cout << "Popped from back: " << myDeque.PopBack() << endl;

    cout << "Front element: " << myDeque.getFront() << endl;
    cout << "Back element: " << myDeque.getBack() << endl;

    cout << "Is the deque empty? " << (myDeque.IsEmpty() ? "Yes" : "No") << endl;

    return 0;
}
