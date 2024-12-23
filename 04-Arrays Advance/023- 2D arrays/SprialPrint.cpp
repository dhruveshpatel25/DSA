/*Spiral Matrix
Given an m x n matrix, return all elements of the matrix in spiral order.

Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

[→ → ↓]
[→ → ↓]
[↑ ← ←]
https://leetcode.com/problems/spiral-matrix/description/*/
#include<iostream>
#include<vector>
using namespace std;

vector<int> WavePrint(vector<vector<int>>& matrix){
    int row=matrix.size();
    int col=matrix[0].size();
    vector<int> ans;
    int count=0;
    int total=row*col;
    int StartingRow=0;
    int StartingCol=0;
    int EndingRow=row-1;
    int EndingCol=col-1;

    //iterate for all the elements
    while(count<total){

        //horizontal iteration (right side)
        for(int index=StartingCol;count<total && index<=EndingCol; index++){
            ans.push_back(matrix[StartingRow][index]);
            count++;
        }
        StartingRow++;

        //vertical iteration (downwards)
        for(int index=StartingRow;count<total && index<=EndingRow;index++){
            ans.push_back(matrix[index][EndingCol]);
            count++;     
        }
        EndingCol--;

        //horizontal iteration (left side)
        for(int index=EndingCol;count<total && index>=StartingCol;index--){
            ans.push_back(matrix[EndingRow][index]);
            count++;   
        }
        EndingRow--;

        //vertical iteration (upwards)
        for(int index=EndingRow;count<total && index>=StartingRow; index--){
            ans.push_back(matrix[index][StartingCol]);
            count++;    
        }
        StartingCol++;
    }
    return ans;
}

int main(){
    vector<vector<int>> matrix={{1,2,3},{4,5,6},{7,8,9}};
    vector<int> result=WavePrint(matrix);
    for(int i:result){
        cout<<i<<" ";
    }
    return 0;
}