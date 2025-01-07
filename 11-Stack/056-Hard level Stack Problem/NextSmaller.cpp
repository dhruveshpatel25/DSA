/*Next Smaller Element
ou are given an array 'ARR' of integers of length N. Your task is to find the next smaller element for each of the array elements.
Next Smaller Element for an array element is the first element to the right of that element which has a value strictly smaller than that element.
If for any array element the next smaller element does not exist, you should print -1 for that array element.

For Example:
If the given array is [ 2, 3, 1], we need to return [1, 1, -1]. Because for  2, 1 is the Next Smaller element. For 3, 1 is the Next Smaller element and for 1, there is no next smaller element hence the answer for this element is -1.
https://www.naukri.com/code360/problems/next-smaller-element_1112581*/
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> NextSmaller(vector<int> &arr,int n){

    stack<int> stk;
    stk.push(-1);
    vector<int> ans(n);

    //iterate from right to left
    for(int i=n-1;i>=0;i--){

        //take the current element
        int curr=arr[i];

        //check if current is smaller or not(so the greater number on the right will be removed as only the next smaller will remain)
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

    vector<int> result = NextSmaller(arr, n);

    cout << "Next smaller elements: ";
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}