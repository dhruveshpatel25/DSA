#include<iostream>
#include<stack>
#include<climits>
#include<vector>
using namespace std;

vector<int> NextSmaller(vector<int> &arr,int n){

    stack<int> stk;
    stk.push(-1);
    vector<int> ans(n);

    for(int i=n-1;i>=0;i--){
        int curr=arr[i];
        while(stk.top()!=-1 && arr[stk.top()]>=curr){
            stk.pop();
        }
        ans[i]=stk.top();
        stk.push(i);
    }
    return ans;
}

vector<int> PrevSmaller(vector<int> &arr,int n){

    stack<int> stk;
    stk.push(-1);
    vector<int> ans(n);

    for(int i=0;i<=n-1;i++){
        int curr=arr[i];
        while(stk.top()!=-1 && arr[stk.top()]>=curr){
            stk.pop();
        }
        ans[i]=stk.top();
        stk.push(i);
    }
    return ans;
}

int LargestRectangleArea(vector<int> &height){
    int n=height.size();

    vector<int> next(n);
    next=NextSmaller(height,n);

    vector<int> prev(n);
    prev=PrevSmaller(height,n);

    int area=INT_MIN;
    for(int i=0;i<n;i++){
        int length=height[i];
        if(next[i]==-1){
            next[i]=n;
        }
        int breadth = next[i]-prev[i]-1;
        int newArea=length*breadth;
        area=max(area,newArea);
    }
    return area;
}

int main() {
    vector<int> heights = {6, 2, 5, 4, 5, 1, 6};
    int maxArea = LargestRectangleArea(heights);
    cout << "The largest rectangle area is: " << maxArea << endl;
    return 0;
}