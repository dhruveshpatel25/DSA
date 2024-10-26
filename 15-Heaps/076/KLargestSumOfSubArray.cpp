#include<iostream>
#include<queue>
using namespace std;

int getKLargest(vector<int> &arr,int k){
    priority_queue<int, vector<int>, greater<int>>pq;
    int n=arr.size();
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            if(pq.size()<k){
                pq.push(sum);
            }else{
                if(sum>pq.top()){
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
    }
    int result=pq.top();
    return result;
}

int main() {
    vector<int> arr = {1,2,3};
    int k = 1;

    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    int result = getKLargest(arr, k);
    cout << "The " << k << "th largest sum is: " << result << endl;

    return 0;
}