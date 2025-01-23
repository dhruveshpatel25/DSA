/*First and Last Position of an Element In Sorted Array
Problem statement
You have been given a sorted array/list 'arr' consisting of ‘n’ elements. You are also given an integer ‘k’.
Now, your task is to find the first and last occurrence of ‘k’ in 'arr'.
Note :
1. If ‘k’ is not present in the array, then the first and the last occurrence will be -1. 
2. 'arr' may contain duplicate elements.

Example:
Input: 'arr' = [0,1,1,5] , 'k' = 1
Output: 1 2
Explanation:
If 'arr' = [0, 1, 1, 5] and 'k' = 1, then the first and last occurrence of 1 will be 1(0 - indexed) and 2.
https://www.naukri.com/code360/problems/first-and-last-position-of-an-element-in-sorted-array_1082549*/
#include<iostream>
using namespace std;

int FirstOccurrence(int arr[], int start, int end, int key, int ans = -1) {

    //base case
    if (start > end) {
        return ans;
    }

    int mid = start + (end - start) / 2;

    if (arr[mid] == key) {

        // Update the answer if the key is found
        ans = mid; 

        // Move to the left part 
        return FirstOccurrence(arr, start, mid - 1, key, ans); 
    } else if (arr[mid] > key) {

        // Key is smaller, search in the left half
        return FirstOccurrence(arr, start, mid - 1, key, ans); 
    } else {

        // Key is larger, search in the right half
        return FirstOccurrence(arr, mid + 1, end, key, ans); 
    }
}

int LastOccurrence(int arr[], int start, int end, int key, int ans = -1) {

    //base case
    if (start > end) {
        return ans;
    }

    int mid = start + (end - start) / 2;

    if (arr[mid] == key) {

        // Update the answer if the key is found
        ans = mid;  

        // Move to the right part
        return LastOccurrence(arr, mid + 1, end, key, ans); 
    } else if (arr[mid] > key) {

        // Key is smaller, search in the left half
        return LastOccurrence(arr, start, mid - 1, key, ans); 
    } else {

        // Key is larger, search in the right half
        return LastOccurrence(arr, mid + 1, end, key, ans); 
    }
}
int main() {
    int arr[] = {1, 1, 2, 2, 2, 2, 4, 4, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 2;

    int first = FirstOccurrence(arr, 0, size - 1, key);
    int last = LastOccurrence(arr, 0, size - 1, key);

    if (first != -1) {
        cout << "The First Occurrence is at index " << first << endl;
    } else {
        cout << "The Key does not exist" << endl;
    }

    if (last != -1) {
        cout << "The Last Occurrence is at index " << last << endl;
    } else {
        cout << "The Key does not exist" << endl;
    }

    return 0;
}