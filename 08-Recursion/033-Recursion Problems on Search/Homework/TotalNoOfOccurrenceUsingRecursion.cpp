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
    int total;
    
    //calculate the difference
    total=(last-first)+1;
    cout<<total;
    return 0;
}