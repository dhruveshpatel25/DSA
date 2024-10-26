#include<iostream>
#include<stack>
using namespace std;

void bottomofstack(stack<int> &mystack, int element){
    if(mystack.empty()){
        mystack.push(element);
        return;
    }

    int num=mystack.top();
    mystack.pop();
    bottomofstack(mystack,element);
    mystack.push(num);
}

void reversestack(stack<int> &mystack){
    if(mystack.empty()){
        return;
    }
    int num=mystack.top();
    mystack.pop();
    reversestack(mystack);
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