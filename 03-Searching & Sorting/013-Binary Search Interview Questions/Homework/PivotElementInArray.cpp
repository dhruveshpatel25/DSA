/*Find Pivot Index
Given an array of integers nums, calculate the pivot index of this array.
The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.
If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.
Return the leftmost pivot index. If no such index exists, return -1.

Example 1:
Input: nums = [1,7,3,6,5,6]
Output: 3
Explanation:
The pivot index is 3.
Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
Right sum = nums[4] + nums[5] = 5 + 6 = 11

Example 2:
Input: nums = [1,2,3]
Output: -1
Explanation:
There is no index that satisfies the conditions in the problem statement.

Example 3:
Input: nums = [2,1,-1]
Output: 0
Explanation:
The pivot index is 0.
Left sum = 0 (no elements to the left of index 0)
Right sum = nums[1] + nums[2] = 1 + -1 = 0
https://leetcode.com/problems/find-pivot-index/description/*/
#include<iostream>
using namespace std;

int Pivot(int arr[], int size){

    //left pointer
    int start=0;

    //right pointer
    int end= size-1;

    //iterate till the left and right pointer dont cross
    while(start<=end){

        //get the middle value
        int mid= start+((end-start)/2);

        //check if the middle element is greater than the first element
        if(arr[mid]>arr[0]){

            //move the left pointer to the right of middle element
            start=mid+1;
        }

        //if the middle element is smaller than the first element
        else{

            //move the right pointer to the left of middle element
            end=mid-1;
        }
    }
    return start;
}
int main(){
    int arr[5]={3,4,5,1,2};
    int result= Pivot(arr,5);
    cout<<"The index at which Pivot took place is "<<result;    
}