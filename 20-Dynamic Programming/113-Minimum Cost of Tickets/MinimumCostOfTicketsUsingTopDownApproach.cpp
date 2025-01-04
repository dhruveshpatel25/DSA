/*Ninja's Trip
Ninja is willing to take some time off from his training and planning a year-long tour. You are given a DAYS array consisting of ‘N’ days when Ninjas will be traveling during the year. Each Day is an integer between 1 to 365 (both inclusive). Train tickets are sold in three different ways:
A 1-day pass is sold for 'COST'[0] coins,
A 7-day pass is sold for 'COST'[1] coins, and
A 30-day  pass is sold for 'COST'[2] coins.
The passes allow for many days of consecutive travel.
Your task is to help the Ninja to find the minimum number of coins required to complete his tour. For example,
If Ninja gets a 7-day pass on day 2, then he can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
https://www.naukri.com/code360/problems/minimum-coins_2180776*/
#include<bits/stdc++.h>
using namespace std;

int solve(int n,vector<int>& days,vector<int>& cost,vector<int>& dp,int index){

    //base case when the index pointer goes out of array
    if(index>=n){
        return 0;
    }

    //memoization
    if(dp[n]!=INT_MAX){
        return dp[n];
    }

    //for one day pass recursivly call for other days
    int oneDayPass = cost[0]+solve(n,days,cost,dp,index+1);

    //pointer
    int i;

    //iterate ahead to check for seven days
    for(i=0;i<n && days[i]<days[index]+7;i++);

    //for weekly pass recursivly call for other days and also by skipping the seven days
    int weeklyPass=cost[1]+solve(n,days,cost,dp,i);

    //iteraet ahead to check for 30 days
    for(i=0;i<n && days[i]<days[index]+30;i++);

    //for monthly pass recusrsivly call for other days and also by skipping the 30 days
    int monthlyPass=cost[2]+solve(n,days,cost,dp,i);

    //save the minimum cost
    dp[index]=min(oneDayPass,min(weeklyPass,monthlyPass));

    //return the minimum value for that days
    return dp[index];
}

int minimumCoins(int n, vector<int> days, vector<int> cost){
    vector<int> dp(n+1,INT_MAX);
    int index=0;
    return solve(n,days,cost,dp,index);
}

int main() {
    int n;
    cout << "Enter the number of travel days: ";
    cin >> n;

    vector<int> days(n);
    cout << "Enter the travel days (space-separated): ";
    for (int i = 0; i < n; i++) {
        cin >> days[i];
    }

    vector<int> cost(3);
    cout << "Enter the costs for 1-day, 7-day, and 30-day passes: ";
    for (int i = 0; i < 3; i++) {
        cin >> cost[i];
    }

    int result = minimumCoins(n, days, cost);
    cout << "The minimum number of coins required is: " << result << endl;

    return 0;
}