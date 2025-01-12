/*Partition Equal Subset Sum
Given an array arr[], return true if it can be partitioned into two subsets such that the sum of elements in both parts is the same, otherwise, false.
Elements should be partitioned such that the each element is used exactly once in each partition.

Examples:

Input: arr = [1, 5, 11, 5]
Output: true
Explanation: The two parts are [1, 5, 5] and [11].

Input: arr = [1, 3, 5]
Output: false
Explanation: This array can never be partitioned into two such parts.
https://www.geeksforgeeks.org/problems/subset-sum-problem2014/1*/
#include<bits/stdc++.h>
using namespace std;

bool solve(vector<int>& arr,int size,int index,int target){
    vector<int> curr(target+1,0);
    vector<int> prev(target+1,0);
    
    prev[0]=1;
    curr[0]=1;

    for(int index=size-1;index>=0;index--){
        for(int t=0;t<=target;t++){
            bool include=0;
            if(target-arr[index]>=0){
                include=prev[t-arr[index]];
            }
            bool exclude=prev[t];
            curr[t]=(include||exclude);
        }
        prev=curr;
    }
    return prev[target];
}

bool solve2(vector<int>& arr,int size,int index,int target){
    vector<int> curr(target+1,0);
    curr[0]=1;

    for(int index=size-1;index>=0;index--){
        for(int t=target;t>=0;t--){
            bool include=0;
            if(target-arr[index]>=0){
                include=curr[t-arr[index]];
            }
            bool exclude=curr[t];
            curr[t]=(include||exclude);
        }
    }
    return curr[target];
}

bool equalPartition(vector<int>& arr) {
    int n=arr.size();
    int total=0;
    for(int i=0;i<n;i++){
        total+=arr[i];
    }
    
    if(total%2==0){
        return solve2(arr,n,0,total/2);
    }else{
        return 0;
    }
}

int main() {
    // Input size of the array
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    // Input array elements
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Check if the array can be partitioned into two subsets with equal sum
    if (equalPartition(arr)) {
        cout << "The array can be partitioned into two subsets with equal sum." << endl;
    } else {
        cout << "The array cannot be partitioned into two subsets with equal sum." << endl;
    }

    return 0;
}
