/*Cut Into Segments
You are given an integer ‘N’ denoting the length of the rod. You need to determine the maximum number of segments you can make of this rod provided that each segment should be of the length 'X', 'Y', or 'Z'.
https://www.naukri.com/code360/problems/cut-into-segments_1214651*/
#include<bits/stdc++.h>
using namespace std;

int solve(int n,int x,int y,int z){

    //dp vector to store for all length
    vector<int> dp(n+1,INT_MIN);

    //for 0 length
    dp[0]=0;

    //iterate for other length
    for(int i=1;i<=n;i++){

        //check if taking x length is feasible
        if(i-x>=0){
            dp[i]=max(dp[i],dp[i-x]+1);
        }

        //check if taking y length is feasible
        if(i-y>=0){
            dp[i]=max(dp[i],dp[i-y]+1);
        }

        //check if taking z length is feasible
        if(i-z>=0){
            dp[i]=max(dp[i],dp[i-z]+1);
        }
    }

    //return answer only if greater than 0
    if(dp[n]<0){
        return 0;
    }else{
        return dp[n];
    }
}

int cutSegments(int n, int x, int y, int z) {
    return solve(n,x,y,z);
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