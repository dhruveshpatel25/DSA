/*Sort a Stack
You’re given a stack consisting of 'N' integers. Your task is to sort this stack in descending order using recursion.
We can only use the following functions on this stack S.
is_empty(S) : Tests whether stack is empty or not.
push(S) : Adds a new element to the stack.
pop(S) : Removes top element from the stack.
top(S) : Returns value of the top element. Note that this function does not remove elements from the stack.

Note :
1) Use of any loop constructs like while, for..etc is not allowed. 
2) The stack may contain duplicate integers.
3) The stack may contain any integer i.e it may either be negative, positive or zero.*/
#include<iostream>
#include<stack>
using namespace std;

void SortInsert(stack<int> &mystack, int num){

    //base case when stack is empty
    //and if not empty check whether the current element is smaller than the top element
    if((mystack.empty()) || (!mystack.empty() && mystack.top()<num)){

        //if smaller push
        mystack.push(num);
        return;
    }

    //take the top element
    int n=mystack.top();

    //remove it
    mystack.pop();

    //recursivly call for lower level
    SortInsert(mystack,num);

    //backtracking-push the element back
    mystack.push(n);
}

void SortStack(stack<int> &mystack){

    //base case
    if(mystack.empty()){
        return;
    }

    //get the top element
    int num=mystack.top();

    //remove it
    mystack.pop();

    //recursivly call for lower level
    SortStack(mystack);

    //when backtracking check on how to insert it
    SortInsert(mystack,num);
}

int main(){
    stack<int> mystack;
    mystack.push(5);
    mystack.push(3);
    mystack.push(8);
    mystack.push(1);
    mystack.push(4);
    SortStack(mystack);
    cout << "Sorted Stack: ";
    while (!mystack.empty()) {
        cout << mystack.top() << " ";
        mystack.pop();
    }
    cout << endl;

    return 0;

}