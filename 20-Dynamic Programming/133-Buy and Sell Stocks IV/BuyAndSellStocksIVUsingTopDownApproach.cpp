/*Best Time to Buy and Sell Stock IV
You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.
Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:
Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.

Example 2:
Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/*/
#include<bits/stdc++.h>
using namespace std;

int solve(int index,int operationNo,int k,vector<int>& prices,vector<vector<int>>& dp){

    //base case
    if(index>=prices.size()){
        return 0;
    }

    if(operationNo==2*k){
        return 0;
    }

    //memoization
    if(dp[index][operationNo]!=-1){
        return dp[index][operationNo];
    }

    int profit=0;

    //buy
    if(operationNo%2==0){

        //include the stock
        //recursivly call by increasing the pointer and flagging buy as false and increasing the operation number
        int include=-prices[index]+solve(index+1,operationNo+1,k,prices,dp);

        //exclude the stock
        //recursivly call by increasing the pointer and flagging buy as true
        int exclude=0+solve(index+1,operationNo,k,prices,dp);

        //saving maximum from both
        profit=max(include,exclude);
    }
    
    //sell
    else{

        //removing the stock
        //recursivly call by increasing the pointer and flagging buy as true and increasing the operation number
        int remove=prices[index]+solve(index+1,operationNo+1,k,prices,dp);

        //keeping the stock
        //recursivly call by increasing the pointer and flagging buy as false
        int keep=0+solve(index+1,operationNo,k,prices,dp);

        //saving maximum from both
        profit=max(remove,keep);
    }

    //keeping the maxium for buy and sell and with operation number
    return dp[index][operationNo]=profit;
}

int maxProfit(int k, vector<int>& prices) {
    int n=prices.size();
    vector<vector<int>> dp(n,vector<int>((2*k)+1,-1));
    return solve(0,0,k,prices,dp);        
}

int main() {
    // Example 1
    int k1 = 2;
    vector<int> prices1 = {2, 4, 1};
    cout << "Example 1: Maximum profit = " << maxProfit(k1, prices1) << endl;

    // Example 2
    int k2 = 2;
    vector<int> prices2 = {3, 2, 6, 5, 0, 3};
    cout << "Example 2: Maximum profit = " << maxProfit(k2, prices2) << endl;

    return 0;
}