#include<iostream>
#include<stack>
using namespace std;

void SortInsert(stack<int> &mystack, int num){
    if((mystack.empty()) || (!mystack.empty() && mystack.top()<num)){
        mystack.push(num);
        return;
    }

    int n=mystack.top();
    mystack.pop();
    SortInsert(mystack,num);
    mystack.push(n);
}

void SortStack(stack<int> &mystack){
    if(mystack.empty()){
        return;
    }

    int num=mystack.top();
    mystack.pop();
    SortStack(mystack);
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