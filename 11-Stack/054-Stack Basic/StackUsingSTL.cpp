#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<int> s;

    //pushing the element
    s.push(1);
    s.push(2);

    //removing the element
    s.pop();

    //getting the top value
    cout<<s.top();

    //getting the size of stack
    cout<<s.size();
}