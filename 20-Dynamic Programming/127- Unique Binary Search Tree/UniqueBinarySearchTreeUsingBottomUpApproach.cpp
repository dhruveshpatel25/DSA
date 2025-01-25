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

int solve(int n){
    vector<int> dp(n+1,0);
    dp[0]=1;
    dp[1]=1;

    //iterate from 2 to n
    for(int i=2;i<=n;i++){

        //iterate from 1 to i
        for(int j=1;j<=i;j++){

            //multiply from every bst from j-1 and i-j
            dp[i]+=dp[j-1]*dp[i-j];
        }
    }
    return dp[n];
}

int numTrees(int n) {
    return solve(n);        
}

int main() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    int result = numTrees(n);
    cout << "The number of structurally unique BSTs is: " << result << endl;

    return 0;
}
