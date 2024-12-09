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

    //make the 0th index as 0
    dp[0]=0;

    //make the 1st index as 1
    dp[1]=1;

    //iterate from 2nd index by saving the value in the array
    for(int i=2;i<=n;i++){

        //add the previous 2 blocks
        dp[i]=dp[i-1]+dp[i-2];
    }

    return dp[n];
}

int main(){
    int place;
    cout<<"Enter the position: ";
    cin>>place;
    vector<int> dp(place+1);
    int result=fibonacci(place,dp);
    cout<<"The value is "<<result;
    return 0;
}