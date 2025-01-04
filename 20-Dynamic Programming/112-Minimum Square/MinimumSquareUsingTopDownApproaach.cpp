/*Get Minimum Squares
Given a number n, find the minimum number of perfect squares (square of an integer) that sum up to n. 

Examples:
Input: n = 100
Output: 1
Explanation: 10 * 10 = 100

Input: n = 6
Output: 3
Explanation = 1 * 1 + 1 * 1 + 2 * 2 = 6 
https://www.geeksforgeeks.org/problems/get-minimum-squares0538/1*/
#include<bits/stdc++.h>
using namespace std;

int solve(int n,vector<int>& dp){

    //base case
    if(n==0){
        return 0;
    }

    //memoization
    if(dp[n]!=-1){
        return dp[n];
    }

    //to tempporary store value
    int ans=n;

    //iterate all possible way
    for(int i=1;i*i<=n;i++){

        //store the minimum way to iterate
        ans=min(ans,solve(n-i*i,dp)+1);
    }

    //store the answer for particular value
    dp[n]=ans;
    return dp[n];
}

int MinSquare(int n){
    vector<int> dp(n+1,-1);
    return solve(n,dp);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int result = MinSquare(n);
    cout << "The minimum number of perfect squares that sum up to " << n << " is: " << result << endl;

    return 0;
}