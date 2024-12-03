#include<iostream>
using namespace std;

int main(){
    int num1,num2;
    cout<<"Enter first number: "<<endl;
    cin>>num1;
    cout<<"Enter second number: "<<endl;
    cin>>num2;

    //check which value is greater
    if(num1>num2){
        cout<<"First Number is greater"<<endl;
    }
    else{
        cout<<"Second Number is greater"<<endl;
    }
    return 0;
}