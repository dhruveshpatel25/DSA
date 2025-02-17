/*Minimum Sideway Jumps
There is a 3 lane road of length n that consists of n + 1 points labeled from 0 to n. A frog starts at point 0 in the second lane and wants to jump to point n. However, there could be obstacles along the way.
You are given an array obstacles of length n + 1 where each obstacles[i] (ranging from 0 to 3) describes an obstacle on the lane obstacles[i] at point i. If obstacles[i] == 0, there are no obstacles at point i. There will be at most one obstacle in the 3 lanes at each point.

For example, if obstacles[2] == 1, then there is an obstacle on lane 1 at point 2.
The frog can only travel from point i to point i + 1 on the same lane if there is not an obstacle on the lane at point i + 1. To avoid obstacles, the frog can also perform a side jump to jump to another lane (even if they are not adjacent) at the same point if there is no obstacle on the new lane.

For example, the frog can jump from lane 3 at point 3 to lane 1 at point 3.
Return the minimum number of side jumps the frog needs to reach any lane at point n starting from lane 2 at point 0.

Note: There will be no obstacles on points 0 and n.

Example 1:
Input: obstacles = [0,1,2,3,0]
Output: 2 
Explanation: The optimal solution is shown by the arrows above. There are 2 side jumps (red arrows).
Note that the frog can jump over obstacles only when making side jumps (as shown at point 2).

Example 2:
Input: obstacles = [0,1,1,3,3,0]
Output: 0
Explanation: There are no obstacles on lane 2. No side jumps are required.

Example 3:
Input: obstacles = [0,2,1,0,3,0]
Output: 2
Explanation: The optimal solution is shown by the arrows above. There are 2 side jumps.
https://leetcode.com/problems/minimum-sideway-jumps/description/*/
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& obstacles,vector<vector<int>>& dp,int currlane,int currpos){
    int end=obstacles.size()-1;

    //base case
    if(currpos==end){
        return 0;
    }

    //memoization
    if(dp[currlane][currpos]!=-1){
        return dp[currlane][currpos];
    }

    //check if we can move forward by checking if there is obstacle in current lane or not
    if(obstacles[currpos+1]!=currlane){

        //if there is no obstacle then increase current position
        return solve(obstacles,dp,currlane,currpos+1);
    }else{

        //if there is obstacle
        int ans=INT_MAX;

        //check for possible position on the lane
        for(int i=1;i<=3;i++){

            //check if we dont jump on same lane and check if there is no obstacle on the lane we are iterating
            if(currlane!=i && obstacles[currpos]!=i){

                //get the minimum jumps
                ans=min(ans,1+solve(obstacles,dp,i,currpos));
            }
        }

        //store the answer
        dp[currlane][currpos]=ans;
        return dp[currlane][currpos];
    }
    
}
int minSideJumps(vector<int>& obstacles) {
    vector<vector<int>> dp(4,vector<int>(obstacles.size(),-1));
    return solve(obstacles,dp,2,0);
}

int main() {
    // Input example
    vector<int> obstacles = {0,2,1,0,3,0};
    
    // Call the function and print the result
    cout << "Minimum sideway jumps: " << minSideJumps(obstacles) << endl;

    return 0;
}
