/*Power of Two
Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2x.
https://leetcode.com/problems/power-of-two/description/*/
#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int number;
    cout<<"Enter the value: ";
    cin>>number;
    bool flag=false;
    for(int i=0; i<=30;i++){
        int answer= pow(2,i);

        //check if the number is power of 2
        if(answer==number){
            cout<<"Is a Power of 2";

            //if true then change the flag value
            flag=true;
        }
    }

    //if not false
    if(flag==false){
        cout<<"Not Power of 2";
    }
}
