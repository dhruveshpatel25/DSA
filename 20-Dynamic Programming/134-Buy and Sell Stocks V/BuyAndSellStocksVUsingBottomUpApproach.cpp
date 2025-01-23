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

int solve(vector<int>& prices,int fee){
    int n=prices.size();
    vector<vector<int>> dp(n+1,vector<int>(2,0));
    for(int index=n-1;index>=0;index--){
        for(int buy=0;buy<=1;buy++){
            int profit=0;
            if(buy==1){
                int include=-prices[index]+dp[index+1][0];
                int exclude=0+dp[index+1][1];
                profit=max(include,exclude);
            }else{
                int remove=prices[index]-fee+dp[index+1][1];
                int keep=0+dp[index+1][0];
                profit=max(remove,keep);
            }
            dp[index][buy]=profit;
        }
    }
    return dp[0][1];
}

int maxProfit(vector<int>& prices,int fee) {
    return solve(prices,fee);        
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