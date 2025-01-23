/*Fractional Knapsack
Given two arrays, val[] and wt[], representing the values and weights of items, and an integer capacity representing the maximum weight a knapsack can hold, determine the maximum total value that can be achieved by putting items in the knapsack. You are allowed to break items into fractions if necessary.
Return the maximum value as a double, rounded to 6 decimal places.

Examples :
Input: val[] = [60, 100, 120], wt[] = [10, 20, 30], capacity = 50
Output: 240.000000
Explanation: Take the item with value 60 and weight 10, value 100 and weight 20 and split the third item with value 120 and weight 30, to fit it into weight 20. so it becomes (120/30)*20=80, so the total value becomes 60+100+80.0=240.0 Thus, total maximum value of item we can have is 240.00 from the given capacity of sack. 

Input: val[] = [60, 100], wt[] = [10, 20], capacity = 50
Output: 160.000000
Explanation: Take both the items completely, without breaking. Total maximum value of item we can have is 160.00 from the given capacity of sack.

Input: val[] = [10, 20, 30], wt[] = [5, 10, 15], capacity = 100
Output: 60.000000
Explanation: In this case, the knapsack capacity exceeds the combined weight of all items (5 + 10 + 15 = 30). Therefore, we can take all items completely, yielding a total maximum value of 10 + 20 + 30 = 60.000000.
https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1*/
#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<double,int> a,pair<double,int> b){
    return a.first>b.first;
}
double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
    int n=val.size();
    vector<pair<double,int>> v;
    for(int i=0;i<n;i++){
        double perUnitValue = val[i]/wt[i];
        pair<double,int> p = make_pair(perUnitValue,i);
        v.push_back(p);
    }

    sort(v.begin(),v.end(),cmp);

    double totalValue=0;
    for(int i=0;i<n;i++){
        int index=v[i].second;
        if(wt[index]>capacity){
            totalValue=totalValue+val[index]*((double)capacity/wt[index]);
            break;
        }else{
            totalValue=totalValue+val[index];
            capacity=capacity-wt[index];
        }
    }

    return totalValue;
}

int main() {
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int capacity = 50;

    cout << fixed << setprecision(6) << fractionalKnapsack(val, wt, capacity) << endl;

    return 0;
}