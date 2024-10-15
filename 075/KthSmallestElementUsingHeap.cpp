#include<iostream>
#include<queue>
using namespace std;

int kthSmallestUsingHeap(int arr[],int left,int right,int k){
    priority_queue<int> pq;
    for(int i=left;i<k;i++){
        pq.push(arr[i]);
    }

    for(int i=k;i<=right;i++){
        if(arr[i]<pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }

    int ans=pq.top();
    return ans;
}

int main() {
    int arr[6] = {7, 10, 4, 3, 20, 5};
    int n = 6;
    int k = 3;

    int result = kthSmallestUsingHeap(arr, 0, n, k);
    cout << "The " << k << "th smallest element is: " << result << endl;

    return 0;
}