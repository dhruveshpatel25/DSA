#include<iostream>
#include<stack>
#include<climits>
#include<vector>
using namespace std;

class Nstack{

    int *arr;
    int *top;
    int *next;

    int numberofstack;
    int size;
    int freespot;

    public:
    Nstack(int numberofstack, int size){
        //allocate memory for storing element 
        arr = new int[size];

        //allocate memory for top indices of each stack 
        top = new int[numberofstack];

        //allocate memory for next free spot or previous top value
        next = new int[size];

        //top array initialise
        for(int i=0;i<numberofstack;i++){
            top[i]=-1;
        }

        //next array initialise
        for(int i=0;i<size;i++){
            next[i]=i+1;
        }

        //update the last index of next to -1
        next[size-1]=-1;

        //initialise freespot
        freespot=0;
    }

    bool push(int element, int stackno){

        //check for overflow
        if(freespot==-1){
            return false;
        }
        //find index from freespot
        int index=freespot;

        //update freespot
        freespot=next[index];

        //insert element to array
        arr[index]=element;

        //update the next array with the previous top value
        next[index]=top[stackno-1];

        //update top
        top[stackno-1]=index;
        return true;
    }

    int pop(int stackno){

        //check underflow
        if(top[stackno-1]==-1){
            return false;
        }

        //get the current top index of the stack
        int index = top[stackno-1];

        //update the top of the stack with previous element in stack
        top[stackno-1] = next[index];

        //update the value in next array to the recent freespot
        next[index]=freespot;

        //update the freespot to next array index
        freespot=index;

        //return the popped value
        return arr[index];
    }
};

int main() {
    int numberOfStacks = 3;
    int stackSize = 10;

    Nstack myStacks(numberOfStacks, stackSize);

    myStacks.push(5, 1);
    myStacks.push(10, 2);

    int poppedElement1 = myStacks.pop(1);
    if (poppedElement1 != -1) {
        cout << "Popped element from stack 1: " << poppedElement1 << endl;
    } else {
        cout << "Stack 1 is empty." << endl;
    }

    int poppedElement2 = myStacks.pop(2);
    if (poppedElement2 != -1) {
        cout << "Popped element from stack 2: " << poppedElement2 << endl;
    } else {
        cout << "Stack 2 is empty." << endl;
    }

    return 0;
}
