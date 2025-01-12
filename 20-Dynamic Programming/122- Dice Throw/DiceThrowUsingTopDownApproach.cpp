/*Dice throw
Given n dice each with m faces. Find the number of ways to get sum x which is the summation of values on each face when all the dice are thrown.

Example:

Input: m = 6, n = 3, x = 12
Output: 25
Explanation: There are 25 total ways to get the Sum 12 using 3 dices with faces from 1 to 6.

Input: m = 2, n = 3, x = 6
Output: 1
Explanation: There is only 1 way to get the Sum 6 using 3 dices with faces from 1 to 2. All the dices will have to land on 2.
https://www.geeksforgeeks.org/problems/dice-throw5349/1*/
#include<bits/stdc++.h>
using namespace std;

int solve(int dices,int faces,int target,vector<vector<int>>& dp){
    if(target<0){
        return 0;
    }

    if(dices==0 && target!=0){
        return 0;
    }

    if(dices!=0 && target==0){
        return 0;
    }

    if(dices==0 && target==0){
        return 1;
    }

    if(dp[dices][target]!=-1){
        return dp[dices][target];
    }
    int ans=0;
    for(int i=1;i<=faces;i++){
        ans=ans+solve(dices-1,faces,target-i,dp);
    }
    dp[dices][target]=ans;
    return dp[dices][target];
}

int noOfWays(int dices, int faces, int target) {
    vector<vector<int>> dp(dices+1,vector<int>(target+1,-1));
    return solve(dices,faces,target,dp);
}

int main() {
    // Input the number of dice, faces, and target sum
    cout << "Enter the number of dice: ";
    int dices;
    cin >> dices;

    cout << "Enter the number of faces on each die: ";
    int faces;
    cin >> faces;

    cout << "Enter the target sum: ";
    int target;
    cin >> target;

    // Call the function to calculate the number of ways
    int result = noOfWays(dices, faces, target);

    // Output the result
    cout << "The number of ways to achieve the target sum is: " << result << endl;

    return 0;
}
