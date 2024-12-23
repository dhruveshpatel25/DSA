/*Modular Exponentiation
You are given a three integers 'X', 'N', and 'M'. Your task is to find ('X' ^ 'N') % 'M'. A ^ B is defined as A raised to power B and A % C is the remainder when A is divided by C.
https://www.naukri.com/code360/problems/modular-exponentiation_1082146*/
#include<iostream>
#include<vector>
using namespace std;

int gcd(int a, int b){

    //if first number is 0
    if(a==0){
        return b;
    }

    //if second number is 0
    if(b==0){
        return a;
    }

    //iterate till both are not same
    while(a!=b){

        //if 1st number is greater
        if(a>b){
            a=a-b;
        }
        
        //if 2nd number is greater
        else{
            b=b-a;
        }
    }

    //return GCD
    return a;
}

int main(){
    int a,b;
    cout<<"Enter the first number ";
    cin>>a;
    cout<<"Enter the second number ";
    cin>>b;
    cout<<gcd(a,b);
}