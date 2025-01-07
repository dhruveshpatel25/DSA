#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> PrevSmaller(vector<int> &arr,int n){

    stack<int> stk;
    stk.push(-1);
    vector<int> ans(n);

    //iterate from left to right
    for(int i=0;i<=n-1;i++){

        //take the current element
        int curr=arr[i];

        //check if current is smaller or not(so the greater number on the left will be removed as only the previous smaller will remain)
        while(stk.top()>curr){
            stk.pop();
        }

        //save the top most element in array
        ans[i]=stk.top();

        //now push the current element in stack
        stk.push(curr);
    }
    return ans;
}

int main() {
    vector<int> arr = {4, 8, 5, 2, 25};
    int n = arr.size();

    vector<int> result = PrevSmaller(arr, n);

    cout << "Next smaller elements: ";
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}