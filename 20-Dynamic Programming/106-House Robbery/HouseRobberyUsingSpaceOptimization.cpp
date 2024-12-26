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

int solve(vector<int> &nums){

    //size of the array
    int size=nums.size();

    //last pointer
    int prev2=0;

    //second last pointer
    int prev1=nums[0];

    //iterate ahead
    for(int i=1;i<size;i++){

        //include= current + next of next value
        int include = prev2+nums[i];

        //exclude=next value
        int exclude = prev1+0;

        //store the maximum
        int ans=max(include,exclude);

        //move the prev2 pointer ahead
        prev2=prev1;

        //move the prev1 pointer ahead
        prev1=ans;
    }
    return prev1;
}

int HouseRobbery(vector<int>& valueInHouse){
    int size=valueInHouse.size();
    if(size==1){
        return valueInHouse[0];
    }
     //to include first element of vector
    vector<int> firstInclude;

    //to include last element of vector
    vector<int> lastInclude;

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

    return max(solve(firstInclude),solve(lastInclude));
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
