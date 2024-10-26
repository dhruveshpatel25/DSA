#include<iostream>
#include<stack>
#include<climits>
#include<vector>
using namespace std;

class SpecialStack{
    stack<int> stk;
    int mini;

    public:
    void push(int data){
        if(stk.empty()){
            stk.push(data);
            mini=data;
        }else{
            if(data<mini){
                stk.push(2*data-mini);
                mini=data;
            }else{
                stk.push(data);
            }
        }
    }

    int pop(){
        if(stk.empty()){
            return -1;
        }
        int curr = stk.top();
        stk.pop();
        if(curr>mini){
            return curr;
        }else{
            int prevmini=mini;
            int val=2*mini-curr;
            mini=val;
            return prevmini;
        }
    }

    int top(){
        if(stk.empty()){
            return -1;
        }
        int curr=stk.top();
        if(curr<mini){
            return mini;
        }else{
            return curr;
        }
    }

    bool IsEmpty(){
        return stk.empty();
    }

    int getmin(){
        if(stk.empty()){
            return -1;
        }

        return mini;
    }
};

int main() {
    SpecialStack s;
    s.push(3);
    s.push(5);
    cout << "Minimum: " << s.getmin() << endl; // Minimum: 3
    s.push(2);
    s.push(1);
    cout << "Minimum: " << s.getmin() << endl; // Minimum: 1
    cout << "Top: " << s.top() << endl; // Top: 1
    cout << "Pop: " << s.pop() << endl; // Pop: 1
    cout << "Minimum: " << s.getmin() << endl; // Minimum: 2
    cout << "Pop: " << s.pop() << endl; // Pop: 2
    cout << "Top: " << s.top() << endl; // Top: 5
    return 0;
}
