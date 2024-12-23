/*Search a 2D Matrix
You are given an m x n integer matrix matrix with the following two properties:
    Each row is sorted in non-decreasing order.
    The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.
You must write a solution in O(log(m * n)) time complexity.

Example 1:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

Example 2:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
https://leetcode.com/problems/search-a-2d-matrix/description/*/
#include<iostream>
#include<vector>
using namespace std;
bool BinarySearch(vector<vector<int>>& matrix, int target ){
    int row=matrix.size();
    int col=matrix[0].size();

    //(0,0)th index
    int start=0;

    //(row,col)th index
    int end=row*col-1;

    //iterate till they cross each other
    while(start<=end){

        //find the middle index
        int mid=start+((end-start)/2);

        //find the middle element
        int element=matrix[mid/col][mid%col];

        //check if the middle element is target
        if(element==target){
            return 1;
        }
        
        //if the target is greater then middle element
        else if(element < target){

            //move the start pointer ahead of middle
            start=mid+1;
        }else{

            //move the end pointer behind middle
            end=mid-1;
        }
    }
    return 0;
}

int main(){
    vector<vector<int>> matrix;
    matrix.push_back({1,2,3});
    matrix.push_back({4,5,6});
    matrix.push_back({7,8,9});
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