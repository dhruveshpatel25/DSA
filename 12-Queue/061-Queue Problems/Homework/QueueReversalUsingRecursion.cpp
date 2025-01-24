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

    //base case
    if(que.empty()){
        return que;
    }

    //take the data
    int data=que.front();

    //remove the data
    que.pop();

    //recursivly call for other elements of queue
    que=reverse(que);

    //when returning push it back
    que.push(data);
    return que;
}

int main() {
    queue<int> que;
    for (int i = 1; i <= 5; i++) {
        que.push(i);
    }

    que = reverse(que);

    while (!que.empty()) {
        cout << que.front() << " ";
        que.pop();
    }

    return 0;
}