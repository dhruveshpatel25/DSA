/*Cut Into Segments
You are given an integer ‘N’ denoting the length of the rod. You need to determine the maximum number of segments you can make of this rod provided that each segment should be of the length 'X', 'Y', or 'Z'.
https://www.naukri.com/code360/problems/cut-into-segments_1214651*/
#include<bits/stdc++.h>
using namespace std;

int solve(int n, int x, int y, int z,vector<int> &dp){

    //base case
    if(n==0){
        return 0;
    }

    //if size goes negative return negative infinity
    if(n<0){
        return INT_MIN;
    }

    //return the value for that element
    if(dp[n]!=-1){
        return dp[n];
    }

    //if x length is taken
    int a=solve(n-x,x,y,z,dp)+1;

    //if y length is taken
    int b=solve(n-y,x,y,z,dp)+1;

    //if z length is taken
    int c=solve(n-z,x,y,z,dp)+1;

    //maximum of all three
    int ans=max(a,max(b,c));

    //stored
    dp[n]=ans;
    return dp[n];
}

int cutSegments(int n, int x, int y, int z) {
    vector<int> dp(n+1,-1);
    int ans=solve(n,x,y,z,dp);
    if(ans<0){
        return 0;
    }else{
        return ans;
    }
}

int main() {
    int n, x, y, z;

    // Input the rod length and possible segment lengths
    cout << "Enter the length of the rod (N): ";
    cin >> n;

    cout << "Enter the length of the first segment (X): ";
    cin >> x;

    cout << "Enter the length of the second segment (Y): ";
    cin >> y;

    cout << "Enter the length of the third segment (Z): ";
    cin >> z;

    // Call the function to calculate the maximum number of segments
    int result = cutSegments(n, x, y, z);

    // Output the result
    cout << "The maximum number of segments that can be made is: " << result << endl;

    return 0;
}
