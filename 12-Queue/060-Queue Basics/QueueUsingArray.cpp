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