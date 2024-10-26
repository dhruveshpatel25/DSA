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
        arr = new int[size];
        top = new int[numberofstack];
        next = new int[size];

        for(int i=0;i<numberofstack;i++){
            top[i]=-1;
        }

        for(int i=0;i<size;i++){
            next[i]=i+1;
        }
        next[size-1]=-1;
        freespot=0;
    }

    bool push(int element, int stackno){
        if(freespot==-1){
            return false;
        }
        int index=freespot;
        freespot=next[index];
        arr[index]=element;
        next[index]=top[stackno-1];
        top[stackno-1]=index;
        return true;
    }

    int pop(int stackno){
        if(top[stackno-1]==-1){
            return false;
        }

        int index = top[stackno-1];
        top[stackno-1] = next[index];
        next[index]=freespot;
        freespot=index;
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
