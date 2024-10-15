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
        if((front==0 && rear==size-1) || (front !=0 && rear==(front-1)%(size-1))){
            cout<<"Queue is Full"<<endl;
        }
        else if(front==-1){
            front=rear=0;
        }
        else if(front==0 && rear != size-1){
            front=size-1;
        }
        else{
            front--;
        }
        arr[front]=data;
    }

    void PushBack(int data){
        if((front==0 && rear==size-1) || (front !=0 && rear==(front-1)%(size-1))){
            cout<<"Queue is Full"<<endl;
        }
        else if(front==-1){
            front=rear=0;
        }
        else if(rear==size-1 && front!=0){
            rear=0;
        }
        else{
            rear++;
        }
        arr[rear]=data;
    }

    int PopFront(){
        if(front==-1){
            return -1;
        }
        int ans=arr[front];
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

    int PopBack(){
        if(front==-1){
            return -1;
        }
        int ans=arr[rear];
        arr[rear]=-1;
        if(front==rear){
            front=rear=-1;
        }
        else if(rear==0){
            rear=size-1;
        }
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
