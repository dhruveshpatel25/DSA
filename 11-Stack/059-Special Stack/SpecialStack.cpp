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

        //for first element
        if(stk.empty()){
            stk.push(data);
            mini=data;
        }else{

            //check data if data is less than the minimum in stack
            if(data<mini){
                stk.push(2*data-mini); //hashing the value as it can use to retrieve the minimum value when pop operation is performed as we have to solve on O(1) space
                mini=data;
            }else{
                //if the data is more than minimum
                stk.push(data);
            }
        }
    }

    int pop(){

        //check underflow
        if(stk.empty()){
            return -1;
        }


        int curr = stk.top();
        stk.pop();

        //if current value from stack in more than minimum value present
        if(curr>mini){
            return curr;
        }else{
            //store the minimum value
            int prevmini=mini;

            //get the previous minimum value from the stack which was hashed in push operation
            int val=2*mini-curr;

            //store the new minimum value
            mini=val;

            //return the minimum value of current stack
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
