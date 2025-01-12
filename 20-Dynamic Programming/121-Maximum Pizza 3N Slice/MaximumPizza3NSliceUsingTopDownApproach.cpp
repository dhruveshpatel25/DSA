/*Pizza With 3n Slices
There is a pizza with 3n slices of varying size, you and your friends will take slices of pizza as follows:
You will pick any pizza slice.
Your friend Alice will pick the next slice in the anti-clockwise direction of your pick.
Your friend Bob will pick the next slice in the clockwise direction of your pick.
Repeat until there are no more slices of pizzas.

Given an integer array slices that represent the sizes of the pizza slices in a clockwise direction, return the maximum possible sum of slice sizes that you can pick.

Example 1:
Input: slices = [1,2,3,4,5,6]
Output: 10
Explanation: Pick pizza slice of size 4, Alice and Bob will pick slices with size 3 and 5 respectively. Then Pick slices with size 6, finally Alice and Bob will pick slice of size 2 and 1 respectively. Total = 4 + 6.

Example 2:
Input: slices = [8,9,8,6,1,1]
Output: 16
Explanation: Pick pizza slice of size 8 in each turn. If you pick slice with size 9 your partners will pick slices of size 8.
https://leetcode.com/problems/pizza-with-3n-slices/description/*/
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& slices,vector<vector<int>>& dp,int index,int endIndex,int k){
    if(k==0 || index>endIndex){
        return 0;
    }

    if(dp[index][k]!=-1){
        return dp[index][k];
    }

    int include=slices[index]+solve(slices,dp,index+2,endIndex,k-1);
    int exclude=0+solve(slices,dp,index+1,endIndex,k);

    dp[index][k]=max(include,exclude);
    return dp[index][k];
}

int maxSizeSlices(vector<int>& slices){
    int n=slices.size();
    int k=n/3;
    vector<vector<int>> dp1(n,vector<int>(k+1,-1));
    int case1=solve(slices,dp1,0,n-2,k);

    vector<vector<int>> dp2(n,vector<int>(k+1,-1));
    int case2=solve(slices,dp2,1,n-1,k);
    return max(case1,case2);
}

int main() {
    // Input the number of slices and their sizes
    cout << "Enter the number of slices (3n): ";
    int n;
    cin >> n;

    // Ensure the input size is valid (must be divisible by 3)
    if (n % 3 != 0) {
        cout << "Invalid input! Number of slices must be divisible by 3." << endl;
        return 0;
    }

    cout << "Enter the sizes of the slices: ";
    vector<int> slices(n);
    for (int i = 0; i < n; ++i) {
        cin >> slices[i];
    }

    // Compute the maximum sum of the slice sizes you can pick
    int result = maxSizeSlices(slices);

    // Print the result
    cout << "Maximum possible sum of slice sizes you can pick: " << result << endl;

    return 0;
}
