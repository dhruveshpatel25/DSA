/*1218. Longest Arithmetic Subsequence of Given Difference
Given an integer array arr and an integer difference, return the length of the longest subsequence in arr which is an arithmetic sequence such that the difference between adjacent elements in the subsequence equals difference.
A subsequence is a sequence that can be derived from arr by deleting some or no elements without changing the order of the remaining elements.

Example 1:
Input: arr = [1,2,3,4], difference = 1
Output: 4
Explanation: The longest arithmetic subsequence is [1,2,3,4].

Example 2:
Input: arr = [1,3,5,7], difference = 1
Output: 1
Explanation: The longest arithmetic subsequence is any single element.

Example 3:
Input: arr = [1,5,7,8,5,3,4,2,1], difference = -2
Output: 4
Explanation: The longest arithmetic subsequence is [7,5,3,1].
https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/description/*/
#include<bits/stdc++.h>
using namespace std;

int longestSubsequence(vector<int>& arr, int difference) {
    unordered_map<int,int> dp;
    int ans=0;
    for(int i=0;i<arr.size();i++){
        int temp=arr[i]-difference;
        int tempAns=0;
        if(dp.count(temp)){
            tempAns=dp[temp];
        }
        dp[arr[i]]=1+tempAns;
        ans=max(ans,dp[arr[i]]);
    }
    return ans;
}

int main() {
    // Example test case 1
    vector<int> arr1 = {1, 2, 3, 4};
    int difference1 = 1;
    cout << "Longest Arithmetic Subsequence of Given Difference for arr1: "
         << longestSubsequence(arr1, difference1) << endl;

    // Example test case 2
    vector<int> arr2 = {1, 3, 5, 7};
    int difference2 = 1;
    cout << "Longest Arithmetic Subsequence of Given Difference for arr2: "
         << longestSubsequence(arr2, difference2) << endl;

    // Example test case 3
    vector<int> arr3 = {1, 5, 7, 8, 5, 3, 4, 2, 1};
    int difference3 = -2;
    cout << "Longest Arithmetic Subsequence of Given Difference for arr3: "
         << longestSubsequence(arr3, difference3) << endl;

    // Additional test case 1
    vector<int> arr4 = {8, 1, 6, 3, 7, 2, 4, 5};
    int difference4 = 1;
    cout << "Longest Arithmetic Subsequence of Given Difference for arr4: "
         << longestSubsequence(arr4, difference4) << endl;

    // Additional test case 2
    vector<int> arr5 = {10, 20, 30, 40, 50};
    int difference5 = 10;
    cout << "Longest Arithmetic Subsequence of Given Difference for arr5: "
         << longestSubsequence(arr5, difference5) << endl;

    return 0;
}
