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

int solve(int k,vector<int>& prices){
    int n=prices.size();

    //current row
    vector<int> curr(2*k+1,0);

    //next row
    vector<int> next(2*k+1,0);

    //iterating all the stocks
    for(int index=n-1;index>=0;index--){

        //different operation number
        for(int operationNo=0;operationNo<2*k;operationNo++){
            int profit=0;

            //buy
            if(operationNo%2==0){

                //including the stock
                int include=-prices[index]+next[operationNo+1];

                //excluding the stock
                int exclude=0+next[operationNo];

                //saving the maximum
                profit=max(include,exclude);
            }else{

                //removing the stock
                int remove=prices[index]+next[operationNo+1];

                //keeping the stock
                int keep=0+next[operationNo];

                //saving the maximum
                profit=max(remove,keep);
            }

            //keeping the maxium for buy and sell and with operation number
            curr[operationNo]=profit;
        }

        //iterating ahead
        next=curr;
    }

    return next[0];
}

int maxProfit(int k, vector<int>& prices) {
    return solve(k,prices);        
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