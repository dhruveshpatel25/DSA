#include<iostream>
#include<queue>
#include<stack>
using namespace std;

queue<int> reverse(queue<int> que){
    stack<int> stk;
    while(!que.empty()){
        int element=que.front();
        que.pop();
        stk.push(element);
    }

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