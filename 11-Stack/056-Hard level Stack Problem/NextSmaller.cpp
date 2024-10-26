#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> NextSmaller(vector<int> &arr,int n){

    stack<int> stk;
    stk.push(-1);
    vector<int> ans(n);

    for(int i=n-1;i>=0;i--){
        int curr=arr[i];
        while(stk.top()>curr){
            stk.pop();
        }
        ans[i]=stk.top();
        stk.push(curr);
    }
    return ans;
}

int main() {
    vector<int> arr = {4, 8, 5, 2, 25};
    int n = arr.size();

    vector<int> result = NextSmaller(arr, n);

    cout << "Next smaller elements: ";
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}