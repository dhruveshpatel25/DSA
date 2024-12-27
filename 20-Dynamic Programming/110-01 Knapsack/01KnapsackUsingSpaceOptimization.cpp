/* 0 1 Knapsack
A thief is robbing a store and can carry a maximal weight of W into his knapsack. There are N items and the ith item weighs wi and is of value vi. Considering the constraints of the maximum weight that a knapsack can carry, you have to find and return the maximum value that a thief can generate by stealing items.
https://www.naukri.com/code360/problems/0-1-knapsack_920542*/
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& weight, vector<int>& value, int index, int maxWeight){

    //previous array
    vector<int> prev(maxWeight+1,0);

    //current array
    vector<int> curr(maxWeight+1,0);

    //base case
    for(int w=weight[0];w<=maxWeight;w++){
        if(weight[0]<maxWeight){
            prev[w]=value[0];
        }else{
            prev[w]=0;
        }
    }

    //for all the element
    for(int i=1;i<index;i++){

        //for all the weight in that element
        for(int w=0;w<=maxWeight;w++){
            int include=0;

            //if that particular weight is possible
            if(weight[i]<=w){

                //current value + the value of remaining weight of upper level
                include=value[i]+prev[w-weight[i]];
            }

            //copy the value from upper level
            int exclude=prev[w];

            //find the maximum of both
            int ans=max(include,exclude);

            //store the maximum
            curr[w]=ans;
        }

        //make the current complete array as previous
        prev=curr;
    }
    return curr[maxWeight];
}

int solve2(vector<int>& weight, vector<int>& value, int n, int maxWeight){

    //current array
    vector<int> curr(maxWeight+1,0);

    //base case
    for(int i=weight[0];i<=maxWeight;i++){
        if(weight[0]<=maxWeight){
            curr[i]=value[0];
        }else{
            curr[i]=0;
        }
    }

    //iterate for all the elements
    for(int i=1;i<n;i++){

        //iterate from backwards of weight
        //this is done because the backward value depend on front value and if they are changed we get wrong answer
        for(int w=maxWeight;w>=0;w--){
            int include=0;

            //if that particular weight is possible
            if(weight[i]<=w){

                //current value + the value of remaining weight of upper level
                include=value[i]+curr[w-weight[i]];
            }

            //copy the value from upper level
            int exclude=curr[w];

            //find the maximum of both
            int ans=max(include,exclude);
            curr[w]=ans;
        }
    }
    return curr[maxWeight];
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
	int ans=solve2(weight,value,n,maxWeight);
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