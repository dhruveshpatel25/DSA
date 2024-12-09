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
int solve(int level,vector<int> cost){

    //save the prev1 as just previous level
    int prev1=cost[1];

    //save the prev2 as previous level
    int prev2=cost[0];

    //if level 
    if(level==0){
        return prev2;
    }

    for(int i=2;i<=level;i++){

        //cost the particular level + minimum of last 2 level
        int curr=cost[i]+min(prev1,prev2);

        //shift prev2 to prev1
        prev2=prev1;

        //shift prev1 to curr
        prev1=curr;
    }
    return prev1;
}
int minCostStair(vector<int>& cost){
    int level=cost.size();
    vector<int> dp(level+1,-1);
    int ans=min(solve(level-1,cost),solve(level-2,cost));
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