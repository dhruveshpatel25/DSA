/*Check if Array Is Sorted and Rotated
Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.
There may be duplicates in the original array.
Note: An array A rotated by x positions results in an array B of the same length such that A[i] == B[(i+x) % A.length], where % is the modulo operation.
Example 1:
Input: nums = [3,4,5,1,2]
Output: true
Explanation: [1,2,3,4,5] is the original sorted array.
You can rotate the array by x = 3 positions to begin on the the element of value 3: [3,4,5,1,2].

Example 2:
Input: nums = [2,1,3,4]
Output: false
Explanation: There is no sorted array once rotated that can make nums.

Example 3:
Input: nums = [1,2,3]
Output: true
Explanation: [1,2,3] is the original sorted array.
You can rotate the array by x = 0 positions (i.e. no rotation) to make nums.
https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/*/
#include<iostream>
#include<vector>
using namespace std;

bool Check(vector<int>& arr){
    int count=0;

    //to check for rotation
    int n=arr.size()-1;
    for(int i=1;i<arr.size();i++){

        //check the previous element with the current element(as it can be rotated so we need to use modulus)
        if(arr[(i-1)%n]>arr[i%n]){

            //increase if only the previous element is greater
            count++;
        }
    }

    //only one time the count will increase in rotated and sorted array when we reach the last element
    return count==1;
}

int main(){
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(6);


    Check(arr);
    cout<<Check(arr);
    return 0;
}