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

        //initialise front and rear array
        for(int i=0;i<numberofqueue;i++){
            front[i]=-1;
            rear[i]=-1;
        }

        //initialise next array
        for(int i=0;i<size;i++){
            next[i]=i+1;
        }

        //updating the last index to -1
        next[size-1]=-1;

        //initialise the freespot
        freespot=0;
    }

    void enqueue(int data,int queueno){

        //check overflow
        if(freespot==-1){
            cout<<"Queue is Full"<<endl;
            return;
        }

        //get the index from freespot    
        int index=freespot;

        //update the freespot from next array
        freespot=next[index];

        //if it is first element then update front array
        if(front[queueno-1]==-1){
            front[queueno-1]=index;
        }

        //if it not then only update next array with rear index
        else{
            next[rear[queueno-1]]=index;
        }

        //no freespot available for that index
        next[index]=-1;

        //save the index in rear array
        rear[queueno-1]=index;

        //push the element
        arr[index]=data;
    }

    int dequeue(int queueno){

        //check underflow
        if(front[queueno-1]==-1){
            cout<<"Queue is Empty"<<endl;
            return -1;
        }

        //get the index value from front queue
        int index = front[queueno-1];

        //update the front array index with the next value of that queue
        front[queueno-1]=next[index];

        //now update the next index with the freespot
        next[index]=freespot;

        //now update the freespot with index
        freespot=index;

        //return the element
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