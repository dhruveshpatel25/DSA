/*Unique Binary Search Trees
Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.

Example 1:
Input: n = 3
Output: 5

Example 2:
Input: n = 1
Output: 1
https://leetcode.com/problems/unique-binary-search-trees/description/*/
#include<bits/stdc++.h>
using namespace std;

int solve(int n,vector<int>& dp){

    //base case
    if(n<=1){
        return 1;
    }

    //memoization
    if(dp[n]!=-1){
        return dp[n];
    }

    int ans=0;

    //iterate for all the nodes possible
    for(int i=1;i<=n;i++){

        //multiply left subtree(containg all unique binary search tree till i) and right subtree(containg all subtree from i to n)
        ans=ans+solve(i-1,dp)*solve(n-i,dp);
    }
    return dp[n]=ans;
}

int numTrees(int n) {
    vector<int> dp(n+1,-1);
    return solve(n,dp);        
}

int main() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    int result = numTrees(n);
    cout << "The number of structurally unique BSTs is: " << result << endl;

    return 0;
}
