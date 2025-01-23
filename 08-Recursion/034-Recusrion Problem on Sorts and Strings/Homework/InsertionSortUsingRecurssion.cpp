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