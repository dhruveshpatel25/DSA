/*Maximum sum of non-adjacent elements
You are given an array/list of ‘N’ integers. You are supposed to return the maximum sum of the subsequence with the constraint that no two elements are adjacent in the given array/list.

Note:
A subsequence of an array/list is obtained by deleting some number of elements (can be zero) from the array/list, leaving the remaining elements in their original order.
https://www.naukri.com/code360/problems/maximum-sum-of-non-adjacent-elements_843261*/
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums){

    //size of the array
    int size=nums.size();

    //tabulation to store each element value
    vector<int> dp(size,0);

    //make the 0th value as element as there could not be any element behind
    dp[0]=nums[0];

    //iterate ahead
    for(int i=1;i<size;i++){

        //include the value + skip one and add next
        int include=(i - 2 >= 0 ? dp[i - 2] : 0)+nums[i];

        //exclude the value + add the next
        int exclude=dp[i-1]+0;

        //store the maximum for that value
        dp[i]=max(include,exclude);
    }
    return dp[size-1];
}

int maximumSum(vector<int> &nums){
    return solve(nums);
}

int main() {
    // Input array
    vector<int> nums = {1,2,3,1,3,5,8,1,9};

    // Call the function to calculate the maximum sum
    int result = maximumSum(nums);

    // Print the result
    cout << "Maximum sum without adjacent elements: " << result << endl;

    return 0; // Indicate successful program termination
}