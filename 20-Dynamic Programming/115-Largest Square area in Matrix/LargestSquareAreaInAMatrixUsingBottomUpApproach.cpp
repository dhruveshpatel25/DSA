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

int solve(vector<vector<int>>& mat,int& maxi){

    //no.of rows
    int rows=mat.size();

    //no.of columns
    int cols=mat[0].size();
    vector<vector<int>> dp(rows+1,vector<int>(cols+1,0));

    //from last row last column to first row first column
    for(int i=rows-1;i>=0;i--){
        for(int j=cols-1;j>=0;j--){

            //right cell
            int right=dp[i][j+1];

            //down cell
            int down=dp[i+1][j];

            //right down diagonal cell
            int diagonal=dp[i+1][j+1];

            //if the cell is 1
            if(mat[i][j]==1){

                //save the minimum value from the 3 cells
                dp[i][j]=1+min(right,min(down,diagonal));

                //store the maximum
                maxi=max(maxi,dp[i][j]);
            }else{

                //if cell 0 return 0
                dp[i][j]=0;
            }
        }
    }
    return dp[0][0];
}

int maxSquare(vector<vector<int>>& mat) {

    //maximum area
    int maxi=0;
    solve(mat,maxi);
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
