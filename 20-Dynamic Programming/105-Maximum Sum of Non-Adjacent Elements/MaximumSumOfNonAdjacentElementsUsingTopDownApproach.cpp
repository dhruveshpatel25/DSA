/*Maximum sum of non-adjacent elements
You are given an array/list of ‘N’ integers. You are supposed to return the maximum sum of the subsequence with the constraint that no two elements are adjacent in the given array/list.

Note:
A subsequence of an array/list is obtained by deleting some number of elements (can be zero) from the array/list, leaving the remaining elements in their original order.
https://www.naukri.com/code360/problems/maximum-sum-of-non-adjacent-elements_843261?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar*/
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums,int size,vector<int>& dp){

    //base case when the pointer is outside the array
    if(size<0){
        return 0;
    }

    //last element
    if(size==0){
        return nums[0];
    }

    //return the maximum for that particular element
    if(dp[size]!=-1){
        return dp[size];
    }

    //including the particular element so we skip the next element
    int include = solve(nums,size-2,dp)+nums[size];

    //excluding the particular element so we go to next element
    int exclude = solve(nums,size-1,dp)+0;

    //store the maximum for that element
    dp[size]=max(include,exclude);
    return dp[size];
}

int maximumSum(vector<int> &nums){
    int size=nums.size();
    vector<int> dp(size+1,-1);
    int ans=solve(nums,size-1,dp);
    return ans;
}

int main() {
    // Input array
    vector<int> nums = {1,2,3,1,3,5,8,1,9};

    // Call the function to calculate the maximum sum
    int result = maximumSum(nums);

    // Print the result
    cout << "Maximum sum without adjacent elements: " << result << endl;

    return 0; // Indicate successful program termination
}