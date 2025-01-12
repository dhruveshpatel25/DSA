/*Partition Equal Subset Sum
Given an array arr[], return true if it can be partitioned into two subsets such that the sum of elements in both parts is the same, otherwise, false.
Elements should be partitioned such that the each element is used exactly once in each partition.

Examples:

Input: arr = [1, 5, 11, 5]
Output: true
Explanation: The two parts are [1, 5, 5] and [11].

Input: arr = [1, 3, 5]
Output: false
Explanation: This array can never be partitioned into two such parts.
https://www.geeksforgeeks.org/problems/subset-sum-problem2014/1*/
#include<bits/stdc++.h>
using namespace std;

bool solve(vector<int>& arr,vector<vector<int>> dp,int index,int target){
    if(index>=arr.size()){
        return 0;
    }

    if(target<0){
        return 0;
    }

    if(target==0){
        return 1;
    }

    if(dp[index][target]!=-1){
        return dp[index][target];
    }

    bool include=solve(arr,dp,index+1,target-arr[index]);
    bool exclude=solve(arr,dp,index+1,target-0);
    return dp[index][target] = (include || exclude);
}

bool equalPartition(vector<int>& arr) {
    int n=arr.size();
    int total=0;
    for(int i=0;i<n;i++){
        total+=arr[i];
    }
    vector<vector<int>> dp(n+1,vector<int>((total/2)+1,-1));
    if(total%2==0){
        return solve(arr,dp,0,total/2);
    }else{
        return 0;
    }
}

int main() {
    // Input size of the array
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    // Input array elements
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Check if the array can be partitioned into two subsets with equal sum
    if (equalPartition(arr)) {
        cout << "The array can be partitioned into two subsets with equal sum." << endl;
    } else {
        cout << "The array cannot be partitioned into two subsets with equal sum." << endl;
    }

    return 0;
}
