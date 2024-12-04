/*Reverse Integer
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
https://leetcode.com/problems/reverse-integer/description/
*/
#include<iostream>
#include<climits>
using namespace std;

int main(){
    int number;
    cout<<"Enter the number: ";
    cin>>number;
    int ans=0;
    while(number!=0){

        int remainder;

        //take the last digit of number
        remainder = number % 10;

        //check the answer if it answer is within the limits
        if(ans>INT_MAX/10 || ans<INT_MIN/10){
            return ans;
        }

        //now move the ans to the higher position to add the remainder
        ans = (ans*10) + remainder;

        //now remove the last digit
        number=number/10;
    }
    cout<<"The reverse for the integer is: "<<ans<<endl;
}