/*Complement of Base 10 Integer
The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.

For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
Given an integer n, return its complement
https://leetcode.com/problems/complement-of-base-10-integer/description/
*/
#include<iostream>
using namespace std;

int main(){
    int number;
    cout<<"Enter the value: ";
    cin>>number;
    int m=number;
    int mask=0;
    int answer;
    while(m!=0){

        //left shift by by 1 so only the 'n' size numbers are flipped 
        mask= (mask<<1)|1;

        //Right shift by 1
        m=m>>1;
    }

    //if the input is 0 return 1
    while(number==0){
        return 1;
    }

    //complementing so we get the answer
    answer = ((~number) & mask );
    cout<<answer;
}