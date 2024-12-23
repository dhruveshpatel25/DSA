/*Search a 2D Matrix II
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:
    Integers in each row are sorted in ascending from left to right.
    Integers in each column are sorted in ascending from top to bottom.
Example 1:
Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
Output: true

Example 2:
Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
Output: false
https://leetcode.com/problems/search-a-2d-matrix-ii/description/*/
#include<iostream>
#include<vector>
using namespace std;

bool BinarySearch(vector<vector<int>>& matrix, int target ){
    int row=matrix.size();
    int col=matrix[0].size();

    int rowIndex=0;
    int colIndex=col-1;
    while(rowIndex < row && colIndex >= 0){
        int element = matrix[rowIndex][colIndex];

        //if the element found is target
        if(element==target){
            return 1;
        }

        //if the target is smaller than the element i.e. it will be present in the upper rows
        else if(element > target){
            colIndex--;
        }
        
        //if the target is greater than the element i.e. it will be present in the left side of martix
        else{
            rowIndex++;
        }
    }
    return 0;
}

int main(){
    vector<vector<int>> matrix;
    matrix.push_back({1,4,7,11,15});
    matrix.push_back({2,5,8,12,19});
    matrix.push_back({3,6,9,16,22});
    matrix.push_back({10,13,14,17,24});
    matrix.push_back({18,21,23,26,30});
    int target;
    cout<<"Enter the element to be searched: ";
    cin>>target;
    bool result = BinarySearch(matrix,target);
    if(result){
        cout<<"The element is present";
    }else{
        cout<<"The element is not present";
    }
}