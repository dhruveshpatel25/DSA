#include<iostream>
#include<stack>
using namespace std;

void bottomofstack(stack<int> &mystack, int element){

    //base case-when stack empty
    if(mystack.empty()){

        //push the element(it used to be top for a particular size)
        mystack.push(element);
        return;
    }

    //get the top of stack
    int num=mystack.top();

    //remove it
    mystack.pop();

    //recursivly call for lower level
    bottomofstack(mystack,element);

    //backtracaking-push when coming back
    mystack.push(num);
}

void reversestack(stack<int> &mystack){

    //base case when stack gets empty
    if(mystack.empty()){
        return;
    }

    //take the top element
    int num=mystack.top();

    //remove it
    mystack.pop();

    //call for below level
    reversestack(mystack);

    //when coming back rescursivly call for that element
    bottomofstack(mystack,num);
}

int main() {
    stack<int> mystack;
    mystack.push(1);
    mystack.push(2);
    mystack.push(3);
    mystack.push(4);
    mystack.push(5);
    reversestack(mystack);
    cout << "Reversed stack: ";
    while (!mystack.empty()) {
        cout << mystack.top() << " ";
        mystack.pop();
    }
    cout << endl;

    return 0;
}