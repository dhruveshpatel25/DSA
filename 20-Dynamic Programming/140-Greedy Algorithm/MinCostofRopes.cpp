/*Minimum Cost of ropes
Given an array, arr[] of rope lengths, connect all ropes into a single rope with the minimum total cost. The cost to connect two ropes is the sum of their lengths. 

Examples:
Input: arr[] = [4, 3, 2, 6]
Output: 29
Explanation: We can connect the ropes in following ways.
1) First connect ropes of lengths 2 and 3. Which makes the array [4, 5, 6]. Cost of this operation 2 + 3 = 5. 
2) Now connect ropes of lengths 4 and 5. Which makes the array [9, 6]. Cost of this operation 4 + 5 = 9.
3) Finally connect the two ropes and all ropes have connected. Cost of this operation 9 + 6 =15. Total cost is 5 + 9 + 15 = 29. This is the optimized cost for connecting ropes. 
Other ways of connecting ropes would always have same or more cost. For example, if we connect 4 and 6 first (we get three rope of 3, 2 and 10), then connect 10 and 3 (we gettwo rope of 13 and 2). Finally we connect 13 and 2. Total cost in this way is 10 + 13 + 15 = 38.

Input: arr[] = [4, 2, 7, 6, 9]
Output: 62 
Explanation: First, connect ropes 4 and 2, which makes the array [6, 7, 6, 9]. Cost of this operation 4 + 2 = 6. 
Next, add ropes 6 and 6, which results in [12, 7, 9]. Cost of this operation 6 + 6 = 12.
Then, add 7 and 9, which makes the array [12,16]. Cost of this operation 7 + 9 = 16. And
finally, add these two which gives [28]. Hence, the total cost is 6 + 12 + 16 + 28 = 62.

Input: arr[] = [10]
Output: 0
Explanation: Since there is only one rope, no connections are needed, so the cost is 0.
https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1*/
#include<bits/stdc++.h>
using namespace std;

int miniCost(int arr[],int numberofropes){

    //queue in ascending order
    priority_queue<int,vector<int>, greater<int>> pq;
    for(int i=0;i<numberofropes;i++){
        pq.push(arr[i]);
    }
    int cost=0;
    while(pq.size()>1){

        //take the first value
        int a=pq.top();
        pq.pop();

        //take the second value
        int b=pq.top();
        pq.pop();

        //sum it
        int sum = a+b;

        //calculate the cost
        cost=cost+sum;

        //push the cost
        pq.push(sum);
    }
    return cost;
}

int main() {
    int arr[] = {4, 3, 2, 6};
    int numberofropes = sizeof(arr)/sizeof(arr[0]);
    int minCost = miniCost(arr, numberofropes);
    cout << "Minimum cost of connecting ropes: " << minCost << endl;
    return 0;
}