/*Rotate Array
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
Example 1:
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

Example 2:
Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
https://leetcode.com/problems/rotate-array/description/*/
#include<iostream>
#include<vector>
using namespace std;

void Rotate(vector<int>& arr,int k){
    int n= arr.size();

    //temporary array
    vector<int> temp(n);
    for(int i=0; i<n;i++){

        //rotating at kth position
        temp[(i+k)%n]=arr[i];
    }

    //copy the temporary array to the original array
    arr=temp;
}
int main(){
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(6);


    Rotate(arr,2);
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    return 0;
} 