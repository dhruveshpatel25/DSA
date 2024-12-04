#include<iostream>
using namespace std;

int main(){
    int number;
    cout<<"Enter the number to be checked ";
    cin>> number;

    //flag for checking the whether it is prime or not
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
