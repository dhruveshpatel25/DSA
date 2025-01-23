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


int solve(vector<int>& prices){
    int n=prices.size();
    vector<vector<int>> curr(2,vector<int>(3,0));
    vector<vector<int>> next(2,vector<int>(3,0));

    for(int index=n-1;index>=0;index--){
        for(int buy=0;buy<=1;buy++){
            for(int limit=1;limit<=2;limit++){
                int profit=0;
                if(buy==1){
                    int include=-prices[index]+next[0][limit];
                    int exclude=0+next[1][limit];
                    profit=max(include,exclude);
                }else{
                    int remove=prices[index]+next[1][limit-1];
                    int keep=0+next[0][limit];
                    profit=max(remove,keep);
                }
                curr[buy][limit]=profit;
            }
            next=curr;
        }
    }
    return next[1][2];
}

int maxProfit(vector<int>& prices) {
    return solve(prices);        
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