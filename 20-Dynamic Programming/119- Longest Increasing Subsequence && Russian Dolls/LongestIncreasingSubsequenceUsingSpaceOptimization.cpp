/*Longest Increasing Subsequence
Given an array arr[] of integers, the task is to find the length of the Longest Strictly Increasing Subsequence (LIS).
A subsequence is considered strictly increasing if each element in the subsequence is strictly less than the next element.

Examples:
Input: arr[] = [5, 8, 3, 7, 9, 1]
Output: 3
Explanation: The longest strictly increasing subsequence could be [5, 7, 9], which has a length of 3.

Input: arr[] = [0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15]
Output: 6
Explanation: One of the possible longest strictly increasing subsequences is [0, 2, 6, 9, 13, 15], which has a length of 6.

Input: arr[] = [3, 10, 2, 1, 20]
Output: 3
Explanation: The longest strictly increasing subsequence could be [3, 10, 20], which has a length of 3.

Input: arr[] = [3, 2]
Output: 1
Explanation: Since there is no strictly increasing subsequence, the longest subsequence is any single element, thus the length is 1.
https://www.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1*/
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr,int n){
    vector<int> currRow(n+1,0);
    vector<int> nextRow(n+1,0);

    //from the last element of array to first
    for(int curr=n-1;curr>=0;curr--){

        //all the previous element of that particular element
        for(int prev=curr-1;prev>=-1;prev--){

            //include element
            int include=0;

            //if it is first element or it is greater than previous
            if(prev==-1 || arr[curr]>arr[prev]){

                //include by addition with previous
                include=1+nextRow[curr+1];
            }

            //exclude element
            int exclude=0+nextRow[prev+1];

            //save the maximum
            int ans=max(include,exclude);
            currRow[prev+1]=ans;
        }

        //iterate ahead
        nextRow=currRow;
    }

    return nextRow[0];
}

int longestSubsequence(vector<int>& arr) {
    int n=arr.size();
    return solve(arr,n);
}

int main() {
    // Input the size of the array
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    // Input the elements of the array
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Call the function to calculate the length of the LIS
    int result = longestSubsequence(arr);

    // Output the result
    cout << "The length of the Longest Increasing Subsequence is: " << result << endl;

    return 0;
}