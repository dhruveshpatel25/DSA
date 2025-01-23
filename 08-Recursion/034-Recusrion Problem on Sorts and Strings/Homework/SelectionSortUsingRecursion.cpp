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
