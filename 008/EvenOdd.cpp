#include<iostream>
using namespace std;
bool IsEven(int value){
    if(value%2==0){
        cout<<"The number is Even";
    }else{
        cout<<"The number is Odd";
    }
}
int main(){
    int number;
    cout<<"Enter the number: ";
    cin>>number;
    IsEven(number);
}