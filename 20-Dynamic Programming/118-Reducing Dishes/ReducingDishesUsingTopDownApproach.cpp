/*Reducing Dishes
A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time.
Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level i.e. time[i] * satisfaction[i].
Return the maximum sum of like-time coefficient that the chef can obtain after preparing some amount of dishes.
Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.

Example 1:
Input: satisfaction = [-1,-8,0,5,-9]
Output: 14
Explanation: After Removing the second and last dish, the maximum total like-time coefficient will be equal to (-1*1 + 0*2 + 5*3 = 14).
Each dish is prepared in one unit of time.

Example 2:
Input: satisfaction = [4,3,2]
Output: 20
Explanation: Dishes can be prepared in any order, (2*1 + 3*2 + 4*3 = 20)

Example 3:
Input: satisfaction = [-1,-4,-5]
Output: 0
Explanation: People do not like the dishes. No dish is prepared.
https://leetcode.com/problems/reducing-dishes/description/*/
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& satisfaction,vector<vector<int>>& dp,int index,int time){

    //base case
    if(index==satisfaction.size()){
        return 0;
    }

    //memoization
    if(dp[index][time]!=-1){
        return dp[index][time];
    }

    //including current dish with time
    int include = satisfaction[index]*(time+1) + solve(satisfaction,dp,index+1,time+1);

    //excluding current dish 
    int exclude = 0 + solve(satisfaction,dp,index+1,time);

    //storing the maximum value
    return dp[index][time]=max(include,exclude);
}

int maxSatisfaction(vector<int>& satisfaction) {
    int n=satisfaction.size();
    sort(satisfaction.begin(),satisfaction.end());
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    return solve(satisfaction,dp,0,0);
}

int main() {
    // Test case: Example 1 from the problem statement
    vector<int> satisfaction = {-1, -8, 0, 5, -9};
    
    // Call the function and print the result
    cout << "Maximum like-time coefficient: " << maxSatisfaction(satisfaction) << endl;

    return 0;
}
