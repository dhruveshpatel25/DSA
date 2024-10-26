#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<int> s;

    s.push(1);
    s.push(2);
    s.pop();
    cout<<s.top();
    cout<<s.size();
}