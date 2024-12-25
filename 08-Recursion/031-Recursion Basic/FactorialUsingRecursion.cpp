#include<iostream>
using namespace std;

int factorial(int num){

    //base case
    if(num==0){
        return 1;
    }

    //recursivly call for n*n-1
    return num*factorial(num-1);
}

int main(){
    int num;
    cout<<"Enter the number: ";
    cin>>num;
    int result=factorial(num);
    cout<<"The factorial of "<<num<<" is "<<result;
    return 0;
}