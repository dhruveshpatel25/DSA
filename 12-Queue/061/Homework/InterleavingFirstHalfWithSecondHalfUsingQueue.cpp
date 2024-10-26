#include<iostream>
#include<queue>
#include<stack>
using namespace std;

queue<int> interleaving(queue<int> que){
    queue<int> newque;

    for(int i=0;i<=que.size();i++){
        int val=que.front();
        que.pop();
        newque.push(val);
    }

    while(!newque.empty()){
        int val=newque.front();
        newque.pop();
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
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);
    myQueue.push(4);
    myQueue.push(5);

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