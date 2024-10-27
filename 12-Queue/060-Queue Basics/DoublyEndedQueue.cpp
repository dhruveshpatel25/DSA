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
