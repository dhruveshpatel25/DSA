/*Minimum Elements
You are given an array of ‘N’ distinct integers and an integer ‘X’ representing the target sum. You have to tell the minimum number of elements you have to take to reach the target sum ‘X’.

Note:
You have an infinite number of elements of each type.
For example
If N=3 and X=7 and array elements are [1,2,3]. 
Way 1 - You can take 4 elements  [2, 2, 2, 1] as 2 + 2 + 2 + 1 = 7.
Way 2 - You can take 3 elements  [3, 3, 1] as 3 + 3 + 1 = 7.
Here, you can see in Way 2 we have used 3 coins to reach the target sum of 7.
Hence the output is 3.
https://www.naukri.com/code360/problems/minimum-elements_3843091?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar*/
#include<bits/stdc++.h>
using namespace std;
/*We can't solve using space optimisation because we need to check for all coins possible so we wouls need targeted array*/
int solve(vector<int> &nums,vector<int> &dp,int target){

    //base case
    if(target==0){
        return 0;
    }

    //base case if it goes negative
    if(target<0){
        return INT_MAX;
    }

    //if the targeted sum is saved with a value
    if(dp[target]!=-1){
        return dp[target];
    }

    //initialize with infinity
    int mini=INT_MAX;

    //iterate for all possible value
    for(int i=0;i<nums.size();i++){

        //the coin taken is subtracted
        int ans=solve(nums,dp,target-nums[i]);

        //if the value returned is not infinity
        if(ans!=INT_MAX){

            //find the minimum possible coins required
            mini=min(mini,1+ans);
        }
    }

    //save the minimum coins for that particular coin
    dp[target]=mini;
    return mini;
}

int minimum(vector<int> &nums,int target){
    vector<int> dp(target+1,-1);
    int ans=solve(nums,dp,target);

    //if the value returned in infinity then return -1
    if(ans==INT_MAX){
        return -1;
    }else{
        return ans;
    }
}
int main() {
    // Number of elements in the array
    int n; 
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    // Input array
    vector<int> nums(n);
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Target sum
    int target; 
    cout << "Enter the target sum: ";
    cin >> target;

    // Function call
    int result = minimum(nums, target);

    // Output the result
    if (result == -1) {
        cout << "It is not possible to reach the target sum." << endl;
    } else {
        cout << "The minimum number of elements required to reach the target sum is: " << result << endl;
    }

    return 0;
}
