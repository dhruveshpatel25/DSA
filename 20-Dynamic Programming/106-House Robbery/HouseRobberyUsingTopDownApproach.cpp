/*House Robber II
Mr. X is a professional robber planning to rob houses along a street. Each house has a certain amount of money hidden.
All houses along this street are arranged in a circle. That means the first house is the neighbour of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses are broken into on the same night.
You are given an array/list of non-negative integers 'ARR' representing the amount of money of each house. Your task is to return the maximum amount of money Mr. X can rob tonight without alerting the police.
Note:
It is possible for Mr. X to rob the same amount of money by looting two different sets of houses. Just print the maximum possible robbed amount, irrespective of sets of houses robbed.

For example:
(i) Given the input array arr[] = {2, 3, 2} the output will be 3 because Mr X cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses. So, he’ll rob only house 2 (money = 3)
(ii) Given the input array arr[] = {1, 2, 3, 1} the output will be 4 because Mr X rob house 1 (money = 1) and then rob house 3 (money = 3).
(iii) Given the input array arr[] = {0} the output will be 0 because Mr. X has got nothing to rob.
https://www.naukri.com/code360/problems/house-robber_839733*/
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>& nums,int size,vector<int>& dp){

    //base case when the pointer is outside the array
    if(size<0){
        return 0;
    }

    //last element
    if(size==0){
        return nums[0];
    }

    //return the maximum for that particular element
    if(dp[size]!=-1){
        return dp[size];
    }

    //including the particular element so we skip the next element
    int include = solve(nums,size-2,dp)+nums[size];

    //excluding the particular element so we go to next element
    int exclude = solve(nums,size-1,dp)+0;

    //store the maximum for that element
    dp[size]=max(include,exclude);
    return dp[size];
}

int HouseRobbery(vector<int>& valueInHouse){

    //size of vector
    int size=valueInHouse.size();

    //if only 1 house
    if(size==1){
        return valueInHouse[0];
    }

    //to include first element of vector
    vector<int> firstInclude;

    //to include last element of vector
    vector<int> lastInclude;

    //for firstInclude
    vector<int> dp1(size+1,-1);

    //for secondInclude
    vector<int> dp2(size+1,-1);
    for(int i=0;i<size;i++){

        //exclude first
        if(i!=0){
            lastInclude.push_back(valueInHouse[i]);
        }

        //exclude last
        if(i!=size-1){
            firstInclude.push_back(valueInHouse[i]);
        }
    }

    return max(solve(firstInclude,size-2,dp1),solve(lastInclude,size-2,dp2));
}
int main() {
    int n;
    cout << "Enter the number of houses: ";
    cin >> n;

    vector<int> valueInHouse(n);
    cout << "Enter the amount of money in each house: ";
    for (int i = 0; i < n; i++) {
        cin >> valueInHouse[i];
    }

    int maxMoney = HouseRobbery(valueInHouse);

    cout << "The maximum amount of money Mr. X can rob is: " << maxMoney << endl;

    return 0;
}
