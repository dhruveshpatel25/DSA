/*Minimum Cost of ropes
Given an array, arr[] of rope lengths, connect all ropes into a single rope with the minimum total cost. The cost to connect two ropes is the sum of their lengths. 
https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1*/
#include<iostream>
#include<queue>
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
