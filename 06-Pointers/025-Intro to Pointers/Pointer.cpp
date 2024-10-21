#include<iostream>
#include<vector>
using namespace std;

int main(){
    int num=5;
    int a = num;
    cout<<"a before "<<num<<endl;
    a++;
    cout<<"a after "<<num<<endl;

    int *ptr=&num;
    cout<<"before "<<*ptr<<endl;
    (*ptr)++;
    cout<<"after "<<*ptr<<endl;

    //copying the pointer
    int *q=ptr;
    cout<<ptr<<"  "<<q<<endl;
    cout<<*ptr<<"  "<<*q<<endl;

    //Arithmetic operation
    int i=5;
    int *p=&i;
    cout<<" before p "<<p<<endl;
    p=p+1;
    cout<<" after p "<<p<<endl;
}