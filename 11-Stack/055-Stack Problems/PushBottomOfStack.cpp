/* Insert An Element At Its Bottom In A Given Stack
You are given a stack/deque of integers 'MY-STACK' and an integer ‘X’. Your task is to insert ‘X’ to the bottom of ‘MY-STACK’ and return the updated stack/deque.

Note :
If ‘MY_STACK’ = [7, 1, 4, 5], then the first element represents the element at the bottom of the stack and the last element represents the element at the top of the stack.
For Example :
Let ‘MY_STACK’ = [7, 1, 4, 5] and ‘X’ = 9. So, ‘MY_STACK’ after insertion becomes [9, 7, 1, 4, 5].
https://www.naukri.com/code360/problems/insert-an-element-at-its-bottom-in-a-given-stack_1171166*/
#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int> &mystack, int x){

    //base case when stack get empty
    if(mystack.empty()){

        //input the value
        mystack.push(x);
        return;
    }

    //take the top element
    int num=mystack.top();

    //remove the element
    mystack.pop();

    //recursivly call for lower level
    solve(mystack,x);

    //backtracking-when coming back push the element removed
    mystack.push(num);
}

stack <int> PushBotttom(stack <int>& mystack, int x){
    solve(mystack,x);
    return mystack;
}

int main() {
    stack<int> mystack;
    mystack.push(1);
    mystack.push(2);
    mystack.push(3);
    int new_element = 4;
    mystack = PushBotttom(mystack, new_element);
    while (!mystack.empty()) {
        cout << mystack.top() << " ";
        mystack.pop();
    }
    cout << endl;

    return 0;
}