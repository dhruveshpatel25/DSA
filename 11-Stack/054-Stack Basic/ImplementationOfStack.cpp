#include<iostream>
using namespace std;

class stack{
    public:
    int *arr;
    int top;
    int size;

    stack(int size){
        this->size=size;
        arr=new int [size];
        top=-1;
    }

    void push(int element){

        //if there is space
        if(size-top>1){
            top++;
            arr[top]=element;
        }
        
        //if there is no space
        else{
            cout<<"Stack Overflow"<<endl;
        }
    }

    void pop(){

        //if there is element
        if(top>=0){
            top--;
        }
        
        //if there is no element
        else{
            cout<<"Stack Underflow"<<endl;
        }
    }

    int peek(){

        //if there is element
        if(top>=0){
            return arr[top];
        }
        
        //if there is no element
        else{
            cout<<"Stack empty";
            return -1;
        }
    }

    bool isEmpty(){
        if(top==-1){
            return true;
        }else{
            return false;
        }
    }
};

int main(){
    stack st(5);
    st.push(1);
    st.push(2);

    st.pop();

    cout<<st.peek();

    st.pop();

    cout<<st.isEmpty();
}