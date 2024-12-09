/*Min Cost Climbing Stairs
You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.
You can either start from the step with index 0, or the step with index 1.
Return the minimum cost to reach the top of the floor.

Example 1:
Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.

Example 2:
Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.
https://leetcode.com/problems/min-cost-climbing-stairs/description/*/
#include<bits/stdc++.h>
using namespace std;
int solve(int level,vector<int>& cost,vector<int>& dp){
    //return for level 0
    dp[0]=cost[0];

    //return for level 1
    dp[1]=cost[1];

    //iteration for other level
    for(int i=2;i<=level;i++){

        //cost of level + minimum of the last 2 level for the particular level 
        dp[i]=cost[i] + min(dp[i-1],dp[i-2]);
    }
    return dp[level];
}
int minCostStair(vector<int>& cost){
    int level=cost.size();
    vector<int> dp(level+1,-1);
    int ans=min(solve(level-1,cost,dp),solve(level-2,cost,dp));
    return ans;
}

int main() {
    // Input: Number of stairs
    int n;
    cout << "Enter the number of stairs: ";
    cin >> n;

    // Input: Cost array
    vector<int> cost(n);
    cout << "Enter the cost for each stair: ";
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }

    // Call the function to compute the minimum cost to reach the top
    int result = minCostStair(cost);

    // Output the result
    cout << "The minimum cost to reach the top is: " << result << endl;

    return 0; // Indicate successful program termination
}
