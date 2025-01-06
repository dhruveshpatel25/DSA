/*Largest square formed in a matrix
Given a binary matrix mat, find out the maximum length of a side of a square sub-matrix with all 1s.

Examples:

Input: mat = [[0, 1, 1, 0, 1], 
              [1, 1, 0, 1, 0],
              [0, 1, 1, 1, 0],
              [1, 1, 1, 1, 0],
              [1, 1, 1, 1, 1],
              [0, 0, 0, 0, 0]]
Output: 3

Input: mat = [[1, 1], 
              [1, 1]]
Output: 2
Explanation: The maximum length of a side of the square sub-matrix is 2. The matrix itself is the maximum sized sub-matrix in this case.

Input: mat = [[0, 0], 
              [0, 0]]
Output: 0
Explanation: There is no 1 in the matrix.
https://www.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/1*/
#include<bits/stdc++.h>
using namespace std;

int solve(int row,int cols,vector<vector<int>>& mat,vector<vector<int>>& dp,int &maxi){

    //if it goes outside
    if(row>=mat.size() || cols>=mat[0].size()){
        return 0;
    }

    //memoization
    if(dp[row][cols]!=-1){
        return dp[row][cols];
    }

    //right cell
    int right=solve(row,cols+1,mat,dp,maxi);

    //down cell
    int down=solve(row+1,cols,mat,dp,maxi);

    //diagonal right-down cell
    int diagonal=solve(row+1,cols+1,mat,dp,maxi);

    //if the cell has 1
    if(mat[row][cols]==1){

        //save the minimum value from the 3 cells
        dp[row][cols]=1+min(right,min(diagonal,down));

        //if maximum area then store its value
        maxi=max(maxi,dp[row][cols]);

        //return the value to the next cells
        return dp[row][cols];
    }else{

        //if 0 then return 0
        return dp[row][cols]=0;
    }
}
int maxSquare(vector<vector<int>>& mat) {

    //row size
    int i=mat.size();

    //column size
    int j=mat[0].size();

    //maximum area
    int maxi=0;

    //dp matrix
    vector<vector<int>> dp(i,vector<int>(j,-1));
    solve(0,0,mat,dp,maxi);
    return maxi;
}

int main() {
    vector<vector<int>> mat = {
        {0, 1, 1, 0, 1},
        {1, 1, 0, 1, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0}
    };

    cout << "Maximum size square: " << maxSquare(mat) << endl;

    return 0;
}

