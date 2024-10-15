#include<iostream>
#include<queue>
using namespace std;

int miniCost(int arr[],int numberofropes){
    priority_queue<int,vector<int>, greater<int>> pq;
    for(int i=0;i<numberofropes;i++){
        pq.push(arr[i]);
    }
    int cost=0;
    while(pq.size()>1){
        int a=pq.top();
        pq.pop();
        int b=pq.top();
        pq.pop();
        int sum = a+b;
        cost=cost+sum;
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
