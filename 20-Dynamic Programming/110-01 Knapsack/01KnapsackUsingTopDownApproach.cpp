/* 0 1 Knapsack
A thief is robbing a store and can carry a maximal weight of W into his knapsack. There are N items and the ith item weighs wi and is of value vi. Considering the constraints of the maximum weight that a knapsack can carry, you have to find and return the maximum value that a thief can generate by stealing items.
https://www.naukri.com/code360/problems/0-1-knapsack_920542*/
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& weight, vector<int>& value, int index, int maxWeight,vector<vector<int> >& dp){

    //if reached the last element of array
    if(index==0){

        //if we can include in bag
        if(weight[index]<=maxWeight){
            return value[index];
        }

        //if we dont
        else{
            return 0;
        }
    }

    //if there is value return the value
    if(dp[index][maxWeight]!=-1){
        return dp[index][maxWeight];
    }
    int include=0;

    //incldue weight if possible
    if(weight[index]<=maxWeight){

        //current weight + recusrivly call next level
        include=value[index]+solve(weight,value,index-1,maxWeight-weight[index],dp);
    }

    //recursivly call next level
    int exclude=solve(weight,value,index-1,maxWeight,dp);

    //store the maximum
    dp[index][maxWeight]=max(include,exclude);
    return dp[index][maxWeight];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {

    //to store for every value and every weight with that value
    vector<vector<int> > dp(n,vector<int>(maxWeight+1,-1));
	int ans=solve(weight,value,n-1,maxWeight,dp);
    return ans;
}

int main() {
    int n; // Number of items
    int maxWeight; // Maximum weight the knapsack can hold

    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> weight(n), value(n);

    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; ++i) {
        cin >> weight[i];
    }

    cout << "Enter the values of the items: ";
    for (int i = 0; i < n; ++i) {
        cin >> value[i];
    }

    cout << "Enter the maximum weight the knapsack can carry: ";
    cin >> maxWeight;

    // Call the knapsack function
    int maxValue = knapsack(weight, value, n, maxWeight);
    cout << "The maximum value that can be carried is: " << maxValue << endl;

    return 0;
}
