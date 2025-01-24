/*Best Time to Buy and Sell Stock II
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.
Find and return the maximum profit you can achieve.

Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.

Example 2:
Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.

Example 3:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/*/
#include<bits/stdc++.h>
using namespace std;

int solve(int index,int buy,vector<int>& prices,vector<vector<int>>& dp){

    //base case
    if(index>=prices.size()){
        return 0;
    }

    //memoization
    if(dp[index][buy]!=-1){
        return dp[index][buy];
    }

    int profit=0;
    if(buy==1){

        //include the stock
        //recursivly call by increasing the pointer and flagging buy as false
        int include=-prices[index]+solve(index+1,0,prices,dp);

        //exclude the stock
        //recursivly call by increasing the pointer and flagging buy as true
        int exclude=0+solve(index+1,1,prices,dp);

        //saving maximum from both
        profit=max(include,exclude);
    }else{

        //removing the stock
        //recursivly call by increasing the pointer and flagging buy as true
        int remove=prices[index]+solve(index+1,1,prices,dp);

        //keeping the stock
        //recursivly call by increasing the pointer and flagging buy as false
        int keep=0+solve(index+1,0,prices,dp);

        //saving maximum from both
        profit=max(remove,keep);
    }

    //keeping the maxium for buy and sell
    return dp[index][buy]=profit;
}

int maxProfit(vector<int>& prices) {
    int n=prices.size();
    vector<vector<int>> dp(n,vector<int>(2,-1));
    return solve(0,1,prices,dp);        
}

int main() {
    // Example 1
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    cout << "Max Profit for Example 1: " << maxProfit(prices1) << endl;

    // Example 2
    vector<int> prices2 = {1, 2, 3, 4, 5};
    cout << "Max Profit for Example 2: " << maxProfit(prices2) << endl;

    // Example 3
    vector<int> prices3 = {7, 6, 4, 3, 1};
    cout << "Max Profit for Example 3: " << maxProfit(prices3) << endl;

    return 0;
}