/*Longest Palindromic Subsequence
Given a string s, find the longest palindromic subsequence's length in s.
A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

Example 1:
Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".

Example 2:
Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".
https://leetcode.com/problems/longest-palindromic-subsequence/description/*/
#include<bits/stdc++.h>
using namespace std;

int solve(string& text1,string& text2,int i,int j,vector<vector<int>>& dp){
    if(i>=text1.size()){
        return 0;
    }

    if(j>=text2.size()){
        return 0;
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans=0;
    if(text1[i]==text2[j]){
        ans=1+solve(text1,text2,i+1,j+1,dp);
    }else{
        ans=max(solve(text1,text2,i+1,j,dp),solve(text1,text2,i,j+1,dp));
    }

    return dp[i][j]=ans;
}

int longestPalindromeSubsequence(string text) {
    string revtext=text;
    reverse(revtext.begin(),revtext.end());
    int n=text.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    return solve(text,revtext,0,0,dp);        
}

int main() {
    // Example 1
    string s1 = "bbbab";
    cout << "Example 1: Longest Palindromic Subsequence length = " 
         << longestPalindromeSubsequence(s1) << endl;

    // Example 2
    string s2 = "cbbd";
    cout << "Example 2: Longest Palindromic Subsequence length = " 
         << longestPalindromeSubsequence(s2) << endl;

    // Additional Test Case 1
    string s3 = "agbdba";
    cout << "Additional Test Case 1: Longest Palindromic Subsequence length = " 
         << longestPalindromeSubsequence(s3) << endl;

    // Additional Test Case 2
    string s4 = "a";
    cout << "Additional Test Case 2: Longest Palindromic Subsequence length = " 
         << longestPalindromeSubsequence(s4) << endl;

    // Additional Test Case 3
    string s5 = "abcde";
    cout << "Additional Test Case 3: Longest Palindromic Subsequence length = " 
         << longestPalindromeSubsequence(s5) << endl;

    return 0;
}