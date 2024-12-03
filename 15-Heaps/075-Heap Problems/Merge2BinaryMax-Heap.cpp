/*Merge two binary Max heaps
Given two binary max heaps as arrays, merge the given heaps to form a new max heap.
https://www.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1*/
#include<iostream>
#include<vector>
using namespace std;

void heapify(vector<int> &arr,int size,int index){
    int largest=index;
    int leftindex=2*index+1;
    int rightindex=2*index+2;

    //check if the left index in inside the count and then compare with largest value
    //if it is larger then swap
    if(leftindex<=size && arr[largest]<arr[leftindex]){
        largest=leftindex;
    }

    //check if the right index in inside the count and then compare with largest value
    //if it is larger then swap
    if(rightindex<=size && arr[largest]<arr[rightindex]){
        largest=rightindex;
    }

    //if there is update swap the largest with the indexed value and then recursivly call for heapify
    if(largest!=index){
        swap(arr[largest],arr[index]);
        heapify(arr,size,largest);
    }
}

vector<int> merge2BinaryMaxHeap(vector<int> &arr1,vector<int> &arr2,int size1,int size2){
    vector<int> ans;

    //push the 1st array in the new array
    for(auto i:arr1){
        ans.push_back(i);
    }

    //push the 2nd array in the new array
    for(auto i:arr2){
        ans.push_back(i);
    }

    int size3=ans.size();

    //now loop from the last half of array
    for(int i=size3/2-1;i>=0;i--){

        
        //recursivly call the heapify function
        heapify(ans,size3-1,i);
    }
    return ans;
}

int main() {
    vector<int> arr1 = {10, 5, 6, 2};
    vector<int> arr2 = {12, 7, 9};
    int size1=arr1.size();
    int size2=arr2.size();

    vector<int> mergedHeap = merge2BinaryMaxHeap(arr1, arr2, size1, size2);

    cout << "Merged Max Heap: ";
    for (int i = 0; i < mergedHeap.size(); ++i) {
        cout << mergedHeap[i] << " ";
    }
    cout << endl;

    return 0;
}