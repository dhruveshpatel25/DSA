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

void Merge(vector<int>& arr1, vector<int>&arr2){

    //pointer for 1st array
    int i=0;

    //pointer for 2nd array
    int j=0;

    //to store the value
    int temp=-1;

    //iterate for both the pointer
    while(i<arr1.size() && j<arr2.size()){

        //check if the element of 1st array is greater than the 2nd array
        //also check if the element in 1st array is not zero
        if(arr1[i]>arr2[j] && arr1[i]!=0){

            //store the element
            temp=arr1[i];

            //push the 2nd array element(smaller)
            arr1[i]=arr2[j];

            //now push the larger element in second array so we can check it again
            arr2[j]=temp;

            //increase the first array pointer
            i++;
        }
        
        //if there exist a 0 in the 1st array
        else if(arr1[i]==0){

            //just push the 2nd array element in 1st array
            arr1[i++]=arr2[j++];
        }
        //if the element in 1st element is smaller just move the pointer ahead
        else{
            i++;
        }
    }
}

int main(){
    vector<int> arr1;
    arr1.push_back(1);
    arr1.push_back(2);
    arr1.push_back(3);
    arr1.push_back(0);
    arr1.push_back(0);
    arr1.push_back(0);

    vector<int> arr2;
    arr2.push_back(2);
    arr2.push_back(5);
    arr2.push_back(6);

    Merge(arr1,arr2);
    for(int i=0; i<arr1.size(); i++){
        cout<<arr1[i]<<" ";
    }
    return 0;
}