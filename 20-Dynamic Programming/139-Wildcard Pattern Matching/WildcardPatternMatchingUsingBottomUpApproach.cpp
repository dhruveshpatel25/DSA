/*Wildcard Matching
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:
'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Example 1:
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:
Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.

Example 3:
Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
https://leetcode.com/problems/wildcard-matching/description/*/
#include<bits/stdc++.h>
using namespace std;

int solve(string& s,string& p){
    int n=s.length();
    int m=p.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));

    dp[0][0]=true;
    for(int j=1;j<=m;j++){
        bool flag=true;
        for(int k=1;k<=j;k++){
            if(p[k-1]!='*'){
                flag=false;
                break;
            }
        }
        dp[0][j]=flag;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==p[j-1] || p[j-1]=='?'){
                dp[i][j]=dp[i-1][j-1];
            }else if(p[j-1]=='*'){
                dp[i][j]=(dp[i-1][j] || dp[i][j-1]);
            }else{
                dp[i][j]= false;
            }
        }
    }
    return dp[n][m];
}

bool isMatch(string s, string p) {
    return solve(s,p);
}

int main() {
    // Example 1
    string s1 = "aa";
    string p1 = "a";
    cout << "Example 1: Is Match? " << (isMatch(s1, p1) ? "true" : "false") << endl;

    // Example 2
    string s2 = "aa";
    string p2 = "*";
    cout << "Example 2: Is Match? " << (isMatch(s2, p2) ? "true" : "false") << endl;

    // Example 3
    string s3 = "cb";
    string p3 = "?a";
    cout << "Example 3: Is Match? " << (isMatch(s3, p3) ? "true" : "false") << endl;

    // Additional Test Case 1
    string s4 = "adceb";
    string p4 = "*a*b";
    cout << "Additional Test Case 1: Is Match? " << (isMatch(s4, p4) ? "true" : "false") << endl;

    // Additional Test Case 2
    string s5 = "acdcb";
    string p5 = "a*c?b";
    cout << "Additional Test Case 2: Is Match? " << (isMatch(s5, p5) ? "true" : "false") << endl;

    // Additional Test Case 3 (Edge case: both strings are empty)
    string s6 = "";
    string p6 = "";
    cout << "Additional Test Case 3: Is Match? " << (isMatch(s6, p6) ? "true" : "false") << endl;

    // Additional Test Case 4 (Edge case: pattern is '*')
    string s7 = "anything";
    string p7 = "*";
    cout << "Additional Test Case 4: Is Match? " << (isMatch(s7, p7) ? "true" : "false") << endl;

    return 0;
}
