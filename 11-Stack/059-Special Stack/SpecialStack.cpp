/*Design a stack that supports getMin() in O(1) time and O(1) extra space
Create a stack data structure that allows operations such as push (adding an element), pop (removing the top element), top (retrieving the top element), and also provides a way to retrieve the minimum element in constant time.

Implement the following public functions :
1. push(data) : This function should take one argument of type integer. It pushes the element into the stack and returns nothing.

2. pop() : It pops the element from the top of the stack and returns nothing.

3. top() : It returns the element being kept at the top of the stack.

4. getMin() : It returns the smallest element present in the stack.

Operations Performed on the Stack:
Query-1(Denoted by an integer 1): Pushes integer data to the stack. (push function)

Query-2(Denoted by an integer 2): Pops the data kept at the top of the stack. (pop function)

Query-3(Denoted by an integer 3): Fetches and returns the data being kept at the top of the stack. (top function)

Query-4(Denoted by an integer 4): Returns the smallest element present in the stack. (getMin() function)
https://www.naukri.com/code360/problems/design-a-stack-that-supports-getmin-in-o-1-time-and-o-1-extra-space_842465*/
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
