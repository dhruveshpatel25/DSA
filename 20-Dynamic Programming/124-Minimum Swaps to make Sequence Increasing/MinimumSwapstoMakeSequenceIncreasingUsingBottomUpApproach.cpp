/*Minimum Swaps To Make Sequences Increasing
You are given two integer arrays of the same length nums1 and nums2. In one operation, you are allowed to swap nums1[i] with nums2[i].

For example, if nums1 = [1,2,3,8], and nums2 = [5,6,7,4], you can swap the element at i = 3 to obtain nums1 = [1,2,3,4] and nums2 = [5,6,7,8].
Return the minimum number of needed operations to make nums1 and nums2 strictly increasing. The test cases are generated so that the given input always makes it possible.
An array arr is strictly increasing if and only if arr[0] < arr[1] < arr[2] < ... < arr[arr.length - 1].

Example 1:
Input: nums1 = [1,3,5,4], nums2 = [1,2,3,7]
Output: 1
Explanation: 
Swap nums1[3] and nums2[3]. Then the sequences are:
nums1 = [1, 3, 5, 7] and nums2 = [1, 2, 3, 4]
which are both strictly increasing.

Example 2:
Input: nums1 = [0,3,5,8,9], nums2 = [2,1,4,6,9]
Output: 1
https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/description/*/
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums1, vector<int>& nums2,int index,bool swapped){
    int n=nums1.size();
    vector<vector<int>> dp(n+1,vector<int>(2,0));
    for(int index=n-1;index>=1;index--){
        for(int swapped=1;swapped>=0;swapped--){
            int ans=INT_MAX;
            int prev1=nums1[index-1];
            int prev2=nums2[index-1];

            if(swapped==1){
                swap(prev1,prev2);
            }

            if(nums1[index]>prev1 && nums2[index]>prev2){
                ans=dp[index+1][0];
            }

            if(nums1[index]>prev2 && nums2[index]>prev1){
                ans=min(ans,1+dp[index+1][1]);
            }

            dp[index][swapped]=ans;
        }
    }
    return dp[index][swapped];
}

int minSwap(vector<int>& nums1, vector<int>& nums2) {
    nums1.insert(nums1.begin(),-1);
    nums2.insert(nums2.begin(),-1);

    int n=nums1.size();

    bool swapped=0;        

    return solve(nums1,nums2,1,swapped);
}

int main() {
    vector<int> nums1 = {1, 3, 5, 4};
    vector<int> nums2 = {1, 2, 3, 7};

    // Test Case 1
    cout << "Minimum swaps for nums1 = [1, 3, 5, 4], nums2 = [1, 2, 3, 7]: "
         << minSwap(nums1, nums2) << endl;

    // Test Case 2
    nums1 = {0, 3, 5, 8, 9};
    nums2 = {2, 1, 4, 6, 9};
    cout << "Minimum swaps for nums1 = [0, 3, 5, 8, 9], nums2 = [2, 1, 4, 6, 9]: "
         << minSwap(nums1, nums2) << endl;

    return 0;
}