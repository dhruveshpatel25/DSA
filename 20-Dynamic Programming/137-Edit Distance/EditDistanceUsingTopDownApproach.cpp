/*Edit Distance
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
You have the following three operations permitted on a word:
Insert a character
Delete a character
Replace a character

Example 1:
Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

Example 2:
Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
https://leetcode.com/problems/edit-distance/description/*/
#include<bits/stdc++.h>
using namespace std;

int solve(string& a,string& b,int i,int j,vector<vector<int>>& dp){
    if(i==a.length()){
        return b.length()-j;
    }

    if(j==b.length()){
        return a.length()-i;
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans=0;
    if(a[i]==b[j]){
        ans=solve(a,b,i+1,j+1,dp);
    }else{
        int insertAns=1+solve(a,b,i,j+1,dp);
        int deleteAns=1+solve(a,b,i+1,j,dp);
        int replaceAns=1+solve(a,b,i+1,j+1,dp);

        ans=min(insertAns,min(deleteAns,replaceAns));
    }

    dp[i][j]=ans;
}

int minDistance(string word1, string word2) {
    int n=word1.length();
    int m=word2.length();

    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    return solve(word1,word2,0,0,dp);        
}

int main() {
    // Example 1
    string word1_1 = "horse";
    string word2_1 = "ros";
    cout << "Example 1: Minimum Edit Distance = " 
         << minDistance(word1_1, word2_1) << endl;

    // Example 2
    string word1_2 = "intention";
    string word2_2 = "execution";
    cout << "Example 2: Minimum Edit Distance = " 
         << minDistance(word1_2, word2_2) << endl;

    // Additional Test Case 1
    string word1_3 = "abc";
    string word2_3 = "def";
    cout << "Additional Test Case 1: Minimum Edit Distance = " 
         << minDistance(word1_3, word2_3) << endl;

    // Additional Test Case 2
    string word1_4 = "kitten";
    string word2_4 = "sitting";
    cout << "Additional Test Case 2: Minimum Edit Distance = " 
         << minDistance(word1_4, word2_4) << endl;

    // Additional Test Case 3
    string word1_5 = "";
    string word2_5 = "abc";
    cout << "Additional Test Case 3: Minimum Edit Distance = " 
         << minDistance(word1_5, word2_5) << endl;

    return 0;
}
