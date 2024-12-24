/*Rotate Image
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]

Example 2:
Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
https://leetcode.com/problems/rotate-image/description/*/
#include<bits/stdc++.h>
using namespace std;

void rotateMatrix(vector<vector<int>> &matrix){

    //iterate all the rows
    for(int i=0;i<matrix.size();i++){

        //iterate all the colums of the row
        for(int j=0;j<i;j++){

            //swap with its diagonal opposite element
            swap(matrix[i][j],matrix[j][i]);
        }
    }

    //reverse each row
    for(int i=0;i<matrix.size();i++){
        reverse(matrix[i].begin(),matrix[i].end());
    }
}

int main() {
    // Example Input: 3x3 matrix
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Original Matrix:" << endl;
    for (const auto &row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    rotateMatrix(matrix);

    cout << "\nRotated Matrix (90 degrees clockwise):" << endl;
    for (const auto &row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}