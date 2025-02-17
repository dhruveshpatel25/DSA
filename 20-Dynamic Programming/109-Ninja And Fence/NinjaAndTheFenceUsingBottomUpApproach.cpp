/*Ninja And The Fence
Ninja has given a fence, and he gave a task to paint this fence. The fence has 'N' posts, and Ninja has 'K' colors. Ninja wants to paint the fence so that not more than two adjacent posts have the same color.
Ninja wonders how many ways are there to do the above task, so he asked for your help.
Your task is to find the number of ways Ninja can paint the fence. Print the answer modulo 10^9 + 7.

Example:
Input: 'N' = 3, 'K' = 2
Output: 6
Say we have the colors with the numbers 1 and 0. We can paint the fence with 3 posts with the following different combinations.
110
001
101
100
010
011
https://www.naukri.com/code360/problems/ninja-and-the-fence_3210208*/
#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int solve(int n,int k){
    vector<int> dp(n+1,-1);

    //if only 1 fence so only 1 way to paint ie k paints
    dp[1]=k;

    //if only 2 fence so only 2 ways
    //both fence same=k
    //both fence different=k*k-1
    dp[2]=(k+k*(k-1))%MOD;

    for(int i=3;i<=n;i++){

        //same so last 2 fence wont be available
        int same=(dp[i-2]*(k-1))%MOD;

        //different so last fence wont be available
        int diff=(dp[i-1]*(k-1))%MOD;
        dp[i]=(same+diff)%MOD;
    }
    return dp[n]; 
}
int numberOfWays(int n, int k) {
    int ans=solve(n,k);
    return ans;
}

int main() {
    int n, k;

    // Input the number of posts and colors
    cout << "Enter the number of posts (N): ";
    cin >> n;

    cout << "Enter the number of colors (K): ";
    cin >> k;

    // Call the function to calculate the number of ways
    int result = numberOfWays(n, k);

    // Output the result
    cout << "The number of ways to paint the fence is: " << result << endl;

    return 0;
}