/*Queue Reversal
Given a queue q containing integer elements, your task is to reverse the queue.

Examples:

Input: q[] = [4 3 1 10 2 6]
Output: [6, 2, 10, 1, 3, 4]
Explanation: After reversing the given elements of the queue, the resultant queue will be 6 2 10 1 3 4.

Input: q[] = [4 3 2 1]
Output: [1, 2, 3, 4]
Explanation: After reversing the given elements of the queue, the resultant queue will be 1 2 3 4.

Input: q[] = [7, 9, 5, 12, 8]
Output: [8, 12, 5, 9, 7]
Explanation: After reversing the given elements of the queue, the resultant queue will be 8, 12, 5, 9, 7.
https://www.geeksforgeeks.org/problems/queue-reversal/1*/
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

queue<int> reverse(queue<int> que){
    stack<int> stk;

    //push the queue in stack
    while(!que.empty()){
        int element=que.front();
        que.pop();
        stk.push(element);
    }

    //pop from stack so it get reverse
    while(!stk.empty()){
        int element=stk.top();
        stk.pop();
        que.push(element);
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

    cout << "Original queue: ";
    while (!myQueue.empty()) {
        cout << myQueue.front() << " ";
        myQueue.pop();
    }
    cout << endl;

    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);
    myQueue.push(4);
    myQueue.push(5);
    myQueue = reverse(myQueue);

    cout << "Reversed queue: ";
    while (!myQueue.empty()) {
        cout << myQueue.front() << " ";
        myQueue.pop();
    }
    cout << endl;

    return 0;
}