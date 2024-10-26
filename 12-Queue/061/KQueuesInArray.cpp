#include<iostream>
#include<queue>
using namespace std;

class KQueue{
    int *arr;
    int *front;
    int *rear;
    int *next;

    int size;
    int numberofqueue;
    int freespot;

    public:
    KQueue(int numberofqueue,int size){
        arr= new int[size];
        front= new int[numberofqueue];
        rear= new int[numberofqueue];
        next=new int[size];

        for(int i=0;i<numberofqueue;i++){
            front[i]=-1;
            rear[i]=-1;
        }

        for(int i=0;i<size;i++){
            next[i]=i+1;
        }
        next[size-1]=-1;
        freespot=0;
    }

    void enqueue(int data,int queueno){
        if(freespot==-1){
            cout<<"Queue is Full"<<endl;
            return;
        }

        int index=freespot;
        freespot=next[index];
        if(front[queueno-1]==-1){
            front[queueno-1]=index;
        }else{
            next[rear[queueno-1]]=index;
        }
        next[index]=-1;
        rear[queueno-1]=index;
        arr[index]=data;
    }

    int dequeue(int queueno){
        if(front[queueno-1]==-1){
            cout<<"Queue is Empty"<<endl;
            return -1;
        }

        int index = front[queueno-1];
        front[queueno-1]=next[index];
        next[index]=freespot;
        freespot=index;
        return arr[index];
    }
};

int main() {

    KQueue q(3, 10);
    q.enqueue(10, 1);
    q.enqueue(15, 1);
    q.enqueue(20, 2);
    q.enqueue(25, 1);

    cout << q.dequeue(1) << endl;
    cout << q.dequeue(2) << endl;
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(1) << endl;

    cout << q.dequeue(1) << endl;

    return 0;
}