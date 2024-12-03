#include<iostream>
#include<queue>
using namespace std;

int main(){

    //priority queue in descending order(larger to smaller)
    priority_queue<int> pq1;
    pq1.push(30);
    pq1.push(40);
    pq1.push(50);
    pq1.push(20);
    pq1.push(10);
    while (pq1.empty() == false) 
    { 
        cout << pq1.top() << " "; 
        pq1.pop(); 
    }
    cout<<endl;

    //priority queue in ascending order(smaller to larger)
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(30);
    pq.push(40);
    pq.push(50);
    pq.push(20);
    pq.push(10);
    while (pq.empty() == false) 
    { 
        cout << pq.top() << " "; 
        pq.pop(); 
    }
}