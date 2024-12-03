/*Kth Smallest
Given an array arr[] and an integer k where k is smaller than the size of the array, the task is to find the kth smallest element in the given array.
https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1*/
#include<iostream>
#include<queue>
using namespace std;

int kthSmallestUsingHeap(int arr[],int left,int right,int k){
    priority_queue<int> pq;

    //push the elements in queue of size k
    for(int i=left;i<k;i++){
        pq.push(arr[i]);
    }

    //now check the element with the maximum value of the heap 
    for(int i=k;i<=right;i++){

        //if smaller then pop the maximum and push the new element
        if(arr[i]<pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }

    //the priority queue will sort it in decreasing order thus giving the top value as kth smallest
    int ans=pq.top();
    return ans;
}

int main() {
    int arr[6] = {7, 10, 4, 3, 20, 5};
    int n = 6;
    int k = 3;

    int result = kthSmallestUsingHeap(arr, 0, n, k);
    cout << "The " << k << "th smallest element is: " << result << endl;

    return 0;
}