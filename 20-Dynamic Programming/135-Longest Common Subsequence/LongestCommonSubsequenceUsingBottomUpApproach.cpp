/*Longest Common Subsequence
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.
A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

Example 1:
Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.

Example 2:
Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.

Example 3:
Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
https://leetcode.com/problems/longest-common-subsequence/description/*/
#include<bits/stdc++.h>
using namespace std;

int solve(string& text1,string& text2){
    int n=text1.size();
    int m=text2.size();

    //tabulation
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));

    //for all the character in first string
    for(int i=n-1;i>=0;i--){

        //for all the character in second string
        for(int j=m-1;j>=0;j--){
            int ans=0;

            //if the text of both string
            if(text1[i]==text2[j]){

                //increase the answer and move the pointer ahead
                ans=1+dp[i+1][j+1];
            }else{

                //if not same then increase either of the pointer
                ans=max(dp[i+1][j],dp[i][j+1]);
            }
            dp[i][j]=ans;
        }
    }
    return dp[0][0];
}

int longestCommonSubsequence(string text1, string text2) {
    return solve(text1,text2);        
}

int main() {
    // Example 1
    string text1_1 = "abcde";
    string text2_1 = "ace";
    cout << "Example 1: Longest Common Subsequence length = " 
         << longestCommonSubsequence(text1_1, text2_1) << endl;

    // Example 2
    string text1_2 = "abc";
    string text2_2 = "abc";
    cout << "Example 2: Longest Common Subsequence length = " 
         << longestCommonSubsequence(text1_2, text2_2) << endl;

    // Example 3
    string text1_3 = "abc";
    string text2_3 = "def";
    cout << "Example 3: Longest Common Subsequence length = " 
         << longestCommonSubsequence(text1_3, text2_3) << endl;

    return 0;
}