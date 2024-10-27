#include<iostream>
#include<queue>
#include<stack>
using namespace std;

queue<int> interleaving(queue<int> que){
    stack<int> stk;
    int halfSize = que.size() / 2;

    //pushing the first half of queue in stack
    for(int i=0;i<halfSize;i++){
        int val=que.front();
        que.pop();
        stk.push(val);
    }

    //pushing the stack in queue
    while(!stk.empty()){
        int val=stk.top();
        stk.pop();
        que.push(val);
    }

    //current first half is pushed back to the queue
    for(int i=0;i<halfSize;i++){
        int val=que.front();
        que.pop();
        que.push(val);
    }

    //now pushing the first half to stack again
    for(int i=0;i<halfSize;i++){
        int val=que.front();
        que.pop();
        stk.push(val);
    }

    //now pushing an element from stack and an element from queue in queue
    while(!stk.empty()){
        int val=stk.top();
        stk.pop();
        que.push(val);
        val=que.front();
        que.pop();
        que.push(val);
    }
    return que;
}

int main() {
    // Create a queue and enqueue some elements
    queue<int> myQueue;
    myQueue.push(11);
    myQueue.push(12);
    myQueue.push(13);
    myQueue.push(14);
    myQueue.push(15);
    myQueue.push(16);
    myQueue.push(17);
    myQueue.push(18);

    // Call interleaving function
    queue<int> interleavedQueue = interleaving(myQueue);

    // Print the interleaved queue
    cout << "Interleaved Queue: ";
    while (!interleavedQueue.empty()) {
        cout << interleavedQueue.front() << " ";
        interleavedQueue.pop();
    }
    cout << endl;

    return 0;
}
