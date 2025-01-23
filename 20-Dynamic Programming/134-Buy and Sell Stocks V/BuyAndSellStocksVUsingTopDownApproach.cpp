/*Best Time to Buy and Sell Stock with Transaction Fee
You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.
Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.
Note:
You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
The transaction fee is only charged once for each stock purchase and sale.
 

Example 1:
Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.

Example 2:
Input: prices = [1,3,7,5,10,3], fee = 3
Output: 6
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/*/
#include<bits/stdc++.h>
using namespace std;

int solve(int index,int buy,int fee,vector<int>& prices,vector<vector<int>>& dp){
    if(index>=prices.size()){
        return 0;
    }

    if(dp[index][buy]!=-1){
        return dp[index][buy];
    }

    int profit=0;
    if(buy==1){
        int include=-prices[index]+solve(index+1,0,fee,prices,dp);
        int exclude=0+solve(index+1,1,fee,prices,dp);
        profit=max(include,exclude);
    }else{
        int remove=prices[index]-fee+solve(index+1,1,fee,prices,dp);
        int keep=0+solve(index+1,0,fee,prices,dp);
        profit=max(remove,keep);
    }
    return dp[index][buy]=profit;
}

int maxProfit(vector<int>& prices, int fee) {
    int n=prices.size();
    vector<vector<int>> dp(n,vector<int>(2,-1));
    return solve(0,1,fee,prices,dp); 
}

int main() {
    // Example 1
    vector<int> prices1 = {1, 3, 2, 8, 4, 9};
    int fee1 = 2;
    cout << "Example 1: Maximum profit = " << maxProfit(prices1, fee1) << endl;

    // Example 2
    vector<int> prices2 = {1, 3, 7, 5, 10, 3};
    int fee2 = 3;
    cout << "Example 2: Maximum profit = " << maxProfit(prices2, fee2) << endl;

    return 0;
}