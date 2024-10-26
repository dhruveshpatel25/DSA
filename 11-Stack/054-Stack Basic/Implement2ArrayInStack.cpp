#include<iostream>
using namespace std;

class stack{
    public:
    int *arr;
    int top1;
    int top2;
    int size;

    stack(int size){
        this->size=size;
        top1=-1;
        top2=size;
        arr=new int[size];
    }

    void push1(int num){
        if(top2-top1>1){
            top1++;
            arr[top1]=num;
        }
    }

    void push2(int num){
        if(top2-top1>1){
            top2--;
            arr[top2]=num;
        }
    }

    int pop1(){
        if(top1>=0){
            int ans=arr[top1];
            top1--;
            return ans;
        }
    }

    int pop2(){
        if(top2<=size){
            int ans=arr[top2];
            top2++;
            return ans;
        }
    }
};

int main() {
    stack myStack(5);

    myStack.push1(10);
    myStack.push1(20);
    myStack.push1(30);

    myStack.push2(40);
    myStack.push2(50);

    cout << "Popping elements from stack 1: ";
    cout << myStack.pop1() << " ";
    cout << myStack.pop1() << " ";
    cout << myStack.pop1() << endl;

    cout << "Popping elements from stack 2: ";
    cout << myStack.pop2() << " ";
    cout << myStack.pop2() << endl;

    return 0;
}