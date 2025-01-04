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

int solve(int n,vector<int>& days,vector<int>& cost){
    vector<int> dp(n+1,INT_MAX);

    //base case
    dp[n]=0;

    //iterate from n-1 to 0th index
    for(int i=n-1;i>=0;i--){

        //for one day pass
        int oneDayPass=cost[0]+dp[i+1];

        //pointer
        int j;

        //check ahead for 7 days if possible then get ahead of 7 days
        for(j=i;j<n && days[j]<days[i]+7;j++);

        //for weekly pass
        int weeklyPass=cost[1]+dp[j];

        //check ahead for 30 days if possible then get ahead of 30 days
        for(j=i;j<n && days[j]<days[i]+30;j++);

        //for monthly pass
        int monthlyPass=cost[2]+dp[j];

        //save the minimum cost
        dp[i]=min(oneDayPass,min(weeklyPass,monthlyPass));
    }
    return dp[0];
}
int minimumCoins(int n, vector<int> days, vector<int> cost){
    return solve(n,days,cost);
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