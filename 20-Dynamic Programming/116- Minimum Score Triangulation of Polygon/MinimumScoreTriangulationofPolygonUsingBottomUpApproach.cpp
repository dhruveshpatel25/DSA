/*Minimum Score Triangulation of Polygon
You have a convex n-sided polygon where each vertex has an integer value. You are given an integer array values where values[i] is the value of the ith vertex in clockwise order.
Polygon triangulation is a process where you divide a polygon into a set of triangles and the vertices of each triangle must also be vertices of the original polygon. Note that no other shapes other than triangles are allowed in the division. This process will result in n - 2 triangles.
You will triangulate the polygon. For each triangle, the weight of that triangle is the product of the values at its vertices. The total score of the triangulation is the sum of these weights over all n - 2 triangles.
Return the minimum possible score that you can achieve with some triangulation of the polygon.

Example 1:
Input: values = [1,2,3]
Output: 6
Explanation: The polygon is already triangulated, and the score of the only triangle is 6.

Example 2:
Input: values = [3,7,4,5]
Output: 144
Explanation: There are two triangulations, with possible scores: 3*7*5 + 4*5*7 = 245, or 3*4*5 + 3*4*7 = 144.
The minimum score is 144.

Example 3:
Input: values = [1,3,1,4,1,5]
Output: 13
Explanation: The minimum score triangulation is 1*1*3 + 1*1*4 + 1*1*5 + 1*1*1 = 13.
https://leetcode.com/problems/minimum-score-triangulation-of-polygon/description/*/
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& values){
    int size=values.size();
    vector<vector<int>> dp(size,vector<int>(size,0));

    //for all possible points
    for(int i=size-1;i>=0;i--){

        //all possible second point(distance should be 2 because there should be atleast 1 point between them)
        for(int j=i+2;j<size;j++){
            int ans=INT_MAX;
            
            //all possible centre points between i & j
            for(int k=i+1;k<j;k++){

                //get the minimum score
                ans=min(ans,values[i]*values[j]*values[k]+dp[i][k]+dp[k][j]);
            }

            //for that i&j points save the data
            dp[i][j]=ans;
        }
    }

    //first and last point so we get the whole polygon
    return dp[0][size-1];
}

int minScoreTriangulation(vector<int>& values) {
    return solve(values);        
}

int main() {
    vector<int> values = {3, 7, 4, 5};
    cout << "Minimum Score Triangulation: " << minScoreTriangulation(values) << endl;
    return 0;
}