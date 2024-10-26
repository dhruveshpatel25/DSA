#include<iostream>
#include<queue>
#include<stack>
using namespace std;

queue<int> reverse(queue<int> que){
    if(que.empty()){
        return que;
    }

    int data=que.front();
    que.pop();
    que=reverse(que);
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