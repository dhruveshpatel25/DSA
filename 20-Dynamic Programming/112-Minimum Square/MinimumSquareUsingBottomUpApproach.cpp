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

int solve(int n){
    vector<int> dp(n+1,INT_MAX);

    //for number 0
    dp[0]=0;

    //iterate for number 1 to n
    for(int i=1;i<=n;i++){

        //all possible squares
        for(int j=1;j*j<=i;j++){

            //checking the condition
            if(i-j*j>=0){

                //getting the minimum value for that number
                dp[i]=min(dp[i],dp[i-j*j]+1);
            }
        }
    }
    return dp[n];
}

int MinSquare(int n){
    return solve(n);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int result = MinSquare(n);
    cout << "The minimum number of perfect squares that sum up to " << n << " is: " << result << endl;

    return 0;
}