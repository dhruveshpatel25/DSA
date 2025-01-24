/*Reverse First K elements of Queue
Given an integer K and a queue of integers, we need to reverse the order of the first K elements of the queue, leaving the other elements in the same relative order.

Only following standard operations are allowed on queue.
enqueue(x) : Add an item x to rear of queue
dequeue() : Remove an item from front of queue
size() : Returns number of elements in queue.
front() : Finds front item.
Note: The above operations represent the general processings. In-built functions of the respective languages can be used to solve the problem.

Example 1:
Input:
5 3
1 2 3 4 5
Output: 
3 2 1 4 5
Explanation: 
After reversing the given
input from the 3rd position the resultant
output will be 3 2 1 4 5.

Example 2:
Input:
4 4
4 3 2 1
Output: 
1 2 3 4
Explanation: 
After reversing the given
input from the 4th position the resultant
output will be 1 2 3 4.
https://www.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1*/
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

queue<int> reverseknumber(queue<int> que,int k){
    stack<int> stk;

    //push the queue in stack
    for(int i=0;i<k;i++){
        int val=que.front();
        que.pop();
        stk.push(val);
    }

    //pop from stack so it get reverse
    while(!stk.empty()){
        int val=stk.top();
        stk.pop();
        que.push(val);
    }
    
    //push the remaing part of queue back to queue
    int rem = que.size()-k;
    while(rem--){
        int val = que.front();
        que.pop();
        que.push(val);
    }

    return que;
}

int main() {

    queue<int> myQueue;
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);
    myQueue.push(4);
    myQueue.push(5);
    int k = 3;
    myQueue = reverseknumber(myQueue, k);

    cout << "Queue after reversing first " << k << " elements: ";
    while (!myQueue.empty()) {
        cout << myQueue.front() << " ";
        myQueue.pop();
    }
    cout << endl;

    return 0;
}
