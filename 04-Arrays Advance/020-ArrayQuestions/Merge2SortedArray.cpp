/*Merge Sorted Array
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
Merge nums1 and nums2 into a single array sorted in non-decreasing order.
The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
Example 1:
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

Example 2:
Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].

Example 3:
Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.
https://leetcode.com/problems/merge-sorted-array/description/*/
#include<iostream>
#include<vector>
using namespace std;

void Merge(vector<int>& arr1,vector<int>& arr2,vector<int>& arr3){

    //pointer for array 1
    int i=0;

    //pointer for array 2
    int j=0;

    //pointer for new array
    int k=0;

    //iterate till both the pointer are inside the array
    while(i<arr1.size() && j<arr2.size()){

        //if the element from 1st array is smaller
        if(arr1[i]<arr2[j]){

            //push the element of 1st array in new array
            arr3[k++]=arr1[i++];
        }
        //if the element of 2nd array is smaller
        else{

            //push the 2nd element array in new array
            arr3[k++]=arr2[j++];
        }
    }

    //iterate only for 1st array if 2nd array is over
    while(i<arr1.size()){
        arr3[k++]=arr1[i++];
    }

    //iterate only for 2nd array if 1st array is over
    while(j<arr2.size()){
        arr3[k++]=arr2[j++];
    }
}

int main(){
    vector<int> arr1;
    arr1.push_back(1);
    arr1.push_back(3);
    arr1.push_back(5);
    arr1.push_back(7);
    arr1.push_back(9);

    vector<int> arr2;
    arr2.push_back(2);
    arr2.push_back(4);
    arr2.push_back(6);
    arr2.push_back(8); 

    vector<int> arr3(arr1.size()+arr2.size());
    Merge(arr1,arr2,arr3);

    for(int i=0; i<arr3.size(); i++){
        cout<<arr3[i]<<" ";
    }
    return 0;
}