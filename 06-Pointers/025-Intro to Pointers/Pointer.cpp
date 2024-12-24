#include<iostream>
#include<vector>
using namespace std;

int main(){
    int num=5;
    int a = num;
    cout<<"a before "<<num<<endl; //returns 5
    a++;
    cout<<"a after "<<num<<endl; //returns 5 because a is changed and not num

    int *ptr=&num;
    cout<<"before "<<*ptr<<endl;  //returns 5
    (*ptr)++;
    cout<<"after "<<*ptr<<endl; //returns 6 as ptr points at num so its value changes

    //copying the pointer
    int *q=ptr;
    cout<<ptr<<"  "<<q<<endl;  // returns the address of ptr and q contains the same address as ptr
    cout<<*ptr<<"  "<<*q<<endl; //returns the value ptr is pointing and same as q

    //Arithmetic operation
    int i=5;
    int *p=&i;
    cout<<" before p "<<p<<endl; //returns address of the value of i
    p=p+1;
    cout<<" after p "<<p<<endl; //returns address of the value changed of i
}