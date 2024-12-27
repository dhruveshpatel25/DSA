/* 0 1 Knapsack
A thief is robbing a store and can carry a maximal weight of W into his knapsack. There are N items and the ith item weighs wi and is of value vi. Considering the constraints of the maximum weight that a knapsack can carry, you have to find and return the maximum value that a thief can generate by stealing items.
https://www.naukri.com/code360/problems/0-1-knapsack_920542*/
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>& weight, vector<int>& value, int index, int maxWeight){

    //to store for every value and every weight with that value
    vector<vector<int>> dp(index,vector<int>(maxWeight+1,0));

    //base case-for first row
    for(int i=weight[0];i<maxWeight;i++) {

        //if last element is possible to keep in bag
        if(weight[0]<=maxWeight){
            dp[0][i]=value[0];
        }else{
            dp[0][i]=0;
        }
    }

    //iterate for other element
    for(int i=1;i<index;i++){

        //iterate for all size till maximum
        for(int w=0;w<=maxWeight;w++){
            int include=0;

            //if that particular weight is possible
            if(weight[i]<=w){

                //current value + the value of remaining weight of upper level
                include=value[i]+dp[i-1][w-weight[i]];
            }

            //copy the value from upper level
            int exclude=dp[i-1][w];

            //find the maximum of both
            int ans=max(include,exclude);

            //store the maximum
            dp[i][w]=ans;
        }
    }
    return dp[index-1][maxWeight];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
	int ans=solve(weight,value,n,maxWeight);
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
