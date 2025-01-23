/*Insertion Sort
You are given ‘N’ integers in the form of an array ‘ARR’. Print the sorted array using the insertion sort.

Note :
No need to return anything. You should sort the array in-place.
For example :
Let ‘ARR’ be: [1, 4, 2]
The sorted array will be: [1, 2, 4].
https://www.naukri.com/code360/problems/insertion-sort_3155179
Input: {2,3,5,4,1}
Output: 2 3 1 5 4 
        1 2 3 5 4 
        1 2 3 5 4 
        1 2 3 4 5 
        1 2 3 4 5*/
#include <iostream>
#include <vector>
using namespace std;

// Recursive function to insert an element in the sorted portion of the array
void insertElement(vector<int> &arr, int n) {
    // Base case: if the array size is 1, it's already sorted
    if (n <= 1){
        return;
    }
    // Sort the first n-1 elements
    insertElement(arr, n - 1);

    // Insert the nth element into its correct position
    int key = arr[n - 1];
    int j = n - 2;

    // Shift elements to the right to create the correct position for the key
    while (j >= 0 && arr[j] > key) {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = key;
}

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    cout << "Original array: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    insertElement(arr, arr.size());

    cout << "Sorted array using Insertion Sort: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}