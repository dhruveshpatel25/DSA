/*Longest Arithmetic Subsequence
Given an array arr[] of sorted and distinct positive integers. The task is to find the length of the longest arithmetic progression in a given array.
Note: A sequence seq is an arithmetic progression if seq[i + 1] - seq[i] are all the same value (for 0 <= i < seq.length - 1).
Examples:

Input:arr[] = [1, 7, 10, 13, 14, 19]
Output: 4
Explanation: The longest arithmetic progression is [1, 7, 13, 19].

Input:arr[] = [2, 4, 6, 8, 10]
Output: 5
Explanation: The whole array is in AP.
https://www.geeksforgeeks.org/problems/longest-arithmetic-progression1019/1*/
#include<bits/stdc++.h>
using namespace std;

int solve(int index,int diff,vector<int>& arr,unordered_map<int,int> dp[]){
    if(index<0){
        return 0;
    }

    if(dp[index].count(diff)){
        return dp[index][diff];
    }

    int ans=0;
    for(int j=index-1;j>=0;j--){
        if(arr[index]-arr[j]==diff){
            ans=max(ans,1+solve(j,diff,arr,dp));
        }
    }
    return dp[index][diff]=ans;
}

int lengthOfLongestAP(vector<int>& arr) {
    int n=arr.size();
    if(n<=2){
        return n;
    }

    int ans=0;
    unordered_map<int,int>dp[n+1];
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            ans=max(ans,2+solve(i,arr[j]-arr[i],arr,dp));
        }
    }
    return ans;
}

int main() {
    // Example test case 1
    vector<int> arr1 = {1, 7, 10, 13, 14, 19};
    cout << "Length of Longest Arithmetic Progression for arr1: "
         << lengthOfLongestAP(arr1) << endl;

    // Example test case 2
    vector<int> arr2 = {2, 4, 6, 8, 10};
    cout << "Length of Longest Arithmetic Progression for arr2: "
         << lengthOfLongestAP(arr2) << endl;

    // Additional test cases
    vector<int> arr3 = {3, 6, 9, 12, 15, 18};
    cout << "Length of Longest Arithmetic Progression for arr3: "
         << lengthOfLongestAP(arr3) << endl;

    vector<int> arr4 = {1, 2, 3, 8, 9, 10};
    cout << "Length of Longest Arithmetic Progression for arr4: "
         << lengthOfLongestAP(arr4) << endl;

    vector<int> arr5 = {1, 5, 9, 13, 17, 21, 25};
    cout << "Length of Longest Arithmetic Progression for arr5: "
         << lengthOfLongestAP(arr5) << endl;

    return 0;
}
