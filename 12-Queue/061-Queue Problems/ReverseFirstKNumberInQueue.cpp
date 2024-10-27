#include<iostream>
#include<queue>
#include<stack>
using namespace std;

queue<int> reverseknumber(queue<int> que,int k){
    stack<int> stk;
    for(int i=0;i<k;i++){
        int val=que.front();
        que.pop();
        stk.push(val);
    }

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
