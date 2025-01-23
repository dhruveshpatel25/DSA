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
#include <vector>
using namespace std;

int findPeakIndex(const vector<int>& arr, int start, int end) {
    // Base case: when start and end pointers converge
    if (start == end) {
        return start;
    }

    int mid = start + (end - start) / 2;

    // Check if mid is part of the increasing sequence
    if (arr[mid] < arr[mid + 1]) {
        return findPeakIndex(arr, mid + 1, end); // Search in the right half
    } else {
        return findPeakIndex(arr, start, mid); // Search in the left half
    }
}

int peakIndexInMountainArray(const vector<int>& arr) {
    return findPeakIndex(arr, 0, arr.size() - 1);
}

int main() {
    vector<int> arr1 = {0, 1, 0};
    vector<int> arr2 = {0, 2, 1, 0};
    vector<int> arr3 = {0, 10, 5, 2};

    cout << "Peak index in arr1: " << peakIndexInMountainArray(arr1) << endl;
    cout << "Peak index in arr2: " << peakIndexInMountainArray(arr2) << endl;
    cout << "Peak index in arr3: " << peakIndexInMountainArray(arr3) << endl;

    return 0;
}