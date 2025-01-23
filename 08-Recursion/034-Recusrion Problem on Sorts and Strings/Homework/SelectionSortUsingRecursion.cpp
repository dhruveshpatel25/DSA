/*Selection Sort
Selection sort is one of the sorting algorithms that works by repeatedly finding the minimum element from the unsorted part of the array and putting it at the beginning of the unsorted region of the array.

You are given an unsorted array consisting of N non-negative integers. Your task is to sort the array in non-decreasing order using the Selection Sort algorithm.
https://www.naukri.com/code360/problems/selection-sort_981162

Input: {2,3,5,4,1}
Output: 2 3 5 4 1 
        1 3 5 4 2 
        1 2 5 4 3 
        1 2 3 4 5 
        1 2 3 4 5 
        1 2 3 4 5*/
#include <iostream>
#include <vector>
using namespace std;

// Recursive function to find the index of the minimum element in the range [start, n-1]
int findMinIndex(vector<int> &arr, int start, int n) {
    if (start == n - 1){
        return start;
    }
    int minIndex = findMinIndex(arr, start + 1, n);
    return (arr[start] < arr[minIndex]) ? start : minIndex;
}

// Recursive function to perform Selection Sort
void selectionSort(vector<int> &arr, int start, int n) {

    // Base case: if the array is fully sorted
    if (start == n - 1){
        return;
    }

    // Find the index of the minimum element and swap it with the first element of the range
    int minIndex = findMinIndex(arr, start, n);
    swap(arr[start], arr[minIndex]);

    // Recursively sort the remaining array
    selectionSort(arr, start + 1, n);
}

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    cout << "Original array: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    selectionSort(arr, 0, arr.size());

    cout << "Sorted array using Selection Sort: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}
