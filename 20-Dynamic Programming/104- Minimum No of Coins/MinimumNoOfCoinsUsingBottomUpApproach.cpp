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
https://www.naukri.com/code360/problems/minimum-elements_3843091*/
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums,int target){
    vector<int> dp(target+1,INT_MAX);
    dp[0]=0;

    //solve for every amount in target
    for(int i=1;i<=target;i++){

        //for that each target iterate for all possible way
        for(int j=0;j<nums.size();j++){

            //check id the sum is not negative and check if the value is not infinity to prevent overfloe
            if(i-nums[j]>=0 && dp[i-nums[j]!=INT_MAX]){

                //check for the minimum coins
                dp[i]=min(dp[i],1+dp[i-nums[j]]);
            }
        }
    }

    //if the targeted value is infinty meaning the is no way
    if(dp[target]==INT_MAX){
        return -1;
    }
    return dp[target];
}

int minimum(vector<int> &nums,int target){
    return solve(nums,target);
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