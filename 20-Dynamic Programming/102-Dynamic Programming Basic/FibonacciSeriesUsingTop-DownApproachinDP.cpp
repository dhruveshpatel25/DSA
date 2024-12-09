/* Nth Fibonacci Number
The n-th term of Fibonacci series F(n), where F(n) is a function, is calculated using the following formula -
F(n) = F(n - 1) + F(n - 2), 
Where, F(1) = 1, F(2) = 1
Provided 'n' you have to find out the n-th Fibonacci Number. Handle edges cases like when 'n' = 1 or 'n' = 2 by using conditionals like if else and return what's expected.
"Indexing is start from 1"

Example :
Input: 6
Output: 8
Explanation: The number is ‘6’ so we have to find the “6th” Fibonacci number.
So by using the given formula of the Fibonacci series, we get the series:    
[ 1, 1, 2, 3, 5, 8, 13, 21]
So the “6th” element is “8” hence we get the output.
https://www.naukri.com/code360/problems/nth-fibonacci-number_74156?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar */
#include<bits/stdc++.h>
using namespace std;

int fibonacci(int n,vector<int>& dp){

    //if n becomes 0
    if(n==0){
        return 0;
    }

    //if n becomes 1
    if(n==1){
        return 1;
    }

    //if there is value in nth position return the value
    if(dp[n]!=-1){
        return dp[n];
    }

    //recursivly call for the function
    dp[n]=fibonacci(n-1,dp)+fibonacci(n-2,dp);
    return dp[n];
}

int main(){
    int place;
    cout<<"Enter the position: ";
    cin>>place;
    vector<int> dp(place+1,-1);
    int result=fibonacci(place,dp);
    cout<<"The value is "<<result;
    return 0;
}