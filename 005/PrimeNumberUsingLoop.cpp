#include<iostream>
using namespace std;

int main(){
    int number;
    cout<<"Enter the number to be checked ";
    cin>> number;
    bool isPrime=true;
    for(int factor = 2; factor<number; factor ++){
        if(number%factor==0){
            cout<<"The number is not Prime Number";
            isPrime=false;
            break;
        }
    }
    if(isPrime==1){
        cout<<"The number is a Prime Number";
    }
}
