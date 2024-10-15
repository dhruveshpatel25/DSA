#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int> &mystack, int x){
    if(mystack.empty()){
        mystack.push(x);
        return;
    }
    int num=mystack.top();
    mystack.pop();
    solve(mystack,x);
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