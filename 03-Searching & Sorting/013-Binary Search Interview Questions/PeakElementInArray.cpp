/*Peak Index in a Mountain Array
You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.
Return the index of the peak element.
Your task is to solve it in O(log(n)) time complexity.

Example 1:
Input: arr = [0,1,0]
Output: 1

Example 2:
Input: arr = [0,2,1,0]
Output: 1

Example 3:
Input: arr = [0,10,5,2]
Output: 1
https://leetcode.com/problems/peak-index-in-a-mountain-array/description/*/
#include<iostream>
using namespace std;

int PeakElement(int arr[],int size){

    //left pointer
    int start=0;

    //right pointer
    int end=size-1;

    //iterate till the left and right pointer dont cross
    while(start<end){

        //get the middle value
        int mid=start+((end-start)/2);

        //check if the middle element is less than the next element
        if(arr[mid]<arr[mid+1]){

            //move the left pointer to the next element
            start=mid+1;
        }
        //if element greater
        else{
            //if greater than move the right pointer to its previous element
            end=mid-1;
        }
        return arr[start];
    }
}
int main(){
    int arr[5]={1,2,3,5,4};
    int result=PeakElement(arr,5);
    cout<<result;
}