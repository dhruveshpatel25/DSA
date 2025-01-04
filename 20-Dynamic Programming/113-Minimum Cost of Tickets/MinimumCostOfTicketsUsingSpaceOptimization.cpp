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
    int ans=0;

    //window approach
    queue<pair<int,int>>week;
    queue<pair<int,int>> month;

    //iterating for all days
    for(int day:days){

        //check if week in not empty and the front day of the queue + 7 is greater than the current day(i.e. in the week)
        if(!week.empty() && week.front().first+7<=day){

            //remove from window
            week.pop();
        }

        //check if month in not empty and the front day of the queue + 30 is greater than the current day(i.e. in the month)
        if(!month.empty() && month.front().first+30<=day){

            //remove from the window
            month.pop();
        }

        //push the day in both the window with the updated cost
        week.push(make_pair(day,ans+cost[1]));
        month.push(make_pair(day,ans+cost[2]));

        //get the minimum value
        ans=min(ans+cost[0],min(week.front().second,month.front().second));
    }
    return ans;
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