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

    //if size is 0
    if(n==0){
        return 0;
    }

    //to store answer
    vector<int> ans;

    //store the first element
    ans.push_back(arr[0]);

    //iterate the array
    for(int i=1;i<n;i++){

        //if the new element is greater than the last element in ans array
        if(arr[i]>ans.back()){

            //push it
            ans.push_back(arr[i]);
        }else{

            //if smaller then check for its position in array
            int index=lower_bound(ans.begin(),ans.end(),arr[i])-ans.begin();

            //erase the old element and put this new value
            ans[index]=arr[i];
        }
    }
    return ans.size();
}

int longestSubsequence(vector<int>& arr) {
    sort(arr.begin(),arr.end());
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