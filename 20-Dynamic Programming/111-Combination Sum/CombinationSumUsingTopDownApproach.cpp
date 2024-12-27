/*Combination Sum IV
You are given an array of distinct integers and you have to tell how many different ways of selecting the elements from the array are there such that the sum of chosen elements is equal to the target number tar.
Note: Two ways are considered the same if for every index the contents of both the ways are equal example way1=[1,2,3,1] and way2= [1,2,3,1] both way1 and way 2 are the same.
But if way1 =[1,2,3,4] and way2= [4,3,2,1] then both ways are different.
Input is given such that the answer will fit in a 32-bit integer. 

For Example:
If N = 3 and tar = 5 and array elements are [1,2,5] then the number of possible ways of making sum = 5 are:
(1,1,1,1,1)
(1,1,1,2)
(1,2,1,1)
(2,1,1,1)
(1,1,2,1)
(2,2,1)
(1,2,2)
(2,1,2)
(5)
Hence the output will be 9.
https://www.naukri.com/code360/problems/number-of-ways_3755252*/
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &num, int tar,vector<int>& dp){

    //if target becomes zero
    if(tar==0){

        //return 1 as it is possible way
        return 1;
    }

    //if target becomes negative
    if(tar<0){

        //return 0 as it is not a possible way
        return 0;
    }

    if(dp[tar]!=-1){
        return dp[tar];
    }

    int ans=0;

    //iterate for all element
    for(int i=0;i<num.size();i++){

        //recursivly solve by decreasing the target
        ans+=solve(num,tar-num[i],dp);
    }

    //save the answer
    dp[tar]=ans;
    return dp[tar];
}

int findWays(vector<int> &num, int tar){
    vector<int> dp(tar+1,-1);
    int ans=solve(num,tar,dp);
    return ans;
}

int main() {
    int n, tar;

    // Input the number of elements in the array
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> num(n);

    // Input the array elements
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    // Input the target sum
    cout << "Enter the target sum: ";
    cin >> tar;

    // Call the findWays function
    int result = findWays(num, tar);

    // Output the result
    cout << "The number of ways to form the target sum is: " << result << endl;

    return 0;
}
