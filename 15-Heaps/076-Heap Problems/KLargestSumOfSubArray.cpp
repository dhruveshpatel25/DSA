/* K-th Largest Sum Subarray
Given an array of integers, find the Kth largest sum subarray For example, given the array [1, -2, 3, -4, 5] and K = 2, the 2nd largest sum subarray would be [3, -4, 5], which has a sum of 4.

Please note that a subarray is the sequence of consecutive elements of the array.
https://www.naukri.com/code360/problems/k-th-largest-sum-contiguous-subarray_920398?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar*/
#include<iostream>
#include<queue>
using namespace std;

int getKLargest(vector<int> &arr,int k){

    //queue in ascending order
    priority_queue<int, vector<int>, greater<int>>pq;
    int n=arr.size();
    //iterate will start for the first value 
    for(int i=0;i<n;i++){

        //for each iterate we create a new sum
        int sum=0;

        //now we do second iteration for entering the value
        for(int j=i;j<n;j++){

            //add to get the sum
            sum+=arr[j];

            //push the sum till it is full
            if(pq.size()<k){
                pq.push(sum);
            }else{ //if it is full check the smallest value 
                if(sum>pq.top()){
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
    }

    //top kth laregest value
    int result=pq.top();
    return result;
}

int main() {
    vector<int> arr = {1,2,3};
    int k = 1;

    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    int result = getKLargest(arr, k);
    cout << "The " << k << "th largest sum is: " << result << endl;

    return 0;
}