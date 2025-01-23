/*Best Time to Buy and Sell Stock III
You are given an array prices where prices[i] is the price of a given stock on the ith day.
Find the maximum profit you can achieve. You may complete at most two transactions.
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:
Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.

Example 2:
Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.

Example 3:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/*/
#include<bits/stdc++.h>
using namespace std;

int solve(int index,int buy,int limit,vector<int>& prices,vector<vector<vector<int>>>& dp){
    if(index>=prices.size()){
        return 0;
    }

    if(limit==0){
        return 0;
    }

    if(dp[index][buy][limit]!=-1){
        return dp[index][buy][limit];
    }

    int profit=0;
    if(buy==1){
        int include=-prices[index]+solve(index+1,0,limit,prices,dp);
        int exclude=0+solve(index+1,1,limit,prices,dp);
        profit=max(include,exclude);
    }else{
        int remove=prices[index]+solve(index+1,1,limit-1,prices,dp);
        int keep=0+solve(index+1,0,limit,prices,dp);
        profit=max(remove,keep);
    }
    return dp[index][buy][limit]=profit;
}

int maxProfit(vector<int>& prices) {
    int n=prices.size();
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
    return solve(0,1,2,prices,dp);        
}

int main() {
    vector<int> prices;
    int n;

    // Input: size of the prices array
    cout << "Enter the number of days (n): ";
    cin >> n;

    // Input: prices for n days
    cout << "Enter the stock prices for " << n << " days: ";
    for (int i = 0; i < n; ++i) {
        int price;
        cin >> price;
        prices.push_back(price);
    }

    // Calculate maximum profit
    int result = maxProfit(prices);

    // Output the result
    cout << "Maximum profit: " << result << endl;

    return 0;
}