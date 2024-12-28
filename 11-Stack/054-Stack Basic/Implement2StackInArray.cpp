/* Two Stacks
Design a data structure, which represents two stacks using only one array common for both stacks. The data structure should support the following operations:

push1(NUM) - Push ‘NUM’ into stack1.
push2(NUM) - Push ‘NUM’ into stack2.
pop1() - Pop out a top element from stack1 and return popped element, in case of underflow return -1.
pop2() - Pop out a top element from stack2 and return popped element, in case of underflow return -1.

There are 2 types of queries in the input
Type 1 - These queries correspond to Push operation.
Type 2 - These queries correspond to Pop operation.

Note:
1. You are given the size of the array.
2. You need to perform push and pop operations in such a way that we are able to push elements in the stack until there is some empty space available in the array.
3. While performing Push operations, do nothing in the situation of the overflow of the stack.
https://www.naukri.com/code360/problems/two-stacks_983634*/
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

        //one pointer at start of array
        top1=-1;

        //second pointer at end of array
        top2=size;
        arr=new int[size];
    }

    //push from first stack
    void push1(int num){

        //if there is a place
        if(top2-top1>1){
            top1++;
            arr[top1]=num;
        }
    }

    //push from second stack
    void push2(int num){

        //if there is a palce
        if(top2-top1>1){
            top2--;
            arr[top2]=num;
        }
    }

    //pop from first stack
    int pop1(){

        //if the element exist
        if(top1>=0){
            int ans=arr[top1];
            top1--;
            return ans;
        }
    }

    //pop from second stack
    int pop2(){

        //if the element exist
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