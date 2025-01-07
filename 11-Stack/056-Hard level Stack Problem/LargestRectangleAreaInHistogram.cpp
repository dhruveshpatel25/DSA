/*Largest Rectangle in Histogram
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

Example 1:
Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.

Example 2:
Input: heights = [2,4]
Output: 4
https://leetcode.com/problems/largest-rectangle-in-histogram/description/*/
#include<iostream>
#include<stack>
#include<climits>
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
        while(stk.top()!=-1 && arr[stk.top()]>=curr){
            stk.pop();
        }

        //save the top most element in array
        ans[i]=stk.top();

        //push the index in stack
        stk.push(i);
    }
    return ans;
}

vector<int> PrevSmaller(vector<int> &arr,int n){

    stack<int> stk;
    stk.push(-1);
    vector<int> ans(n);

    //iterate from left to right
    for(int i=0;i<=n-1;i++){

        //take the current element
        int curr=arr[i];

        //check if current is smaller or not(so the greater number on the left will be removed as only the previous smaller will remain)
        while(stk.top()!=-1 && arr[stk.top()]>=curr){
            stk.pop();
        }

        //save the top most element in array
        ans[i]=stk.top();

        //push the index in stack
        stk.push(i);
    }
    return ans;
}

int LargestRectangleArea(vector<int> &height){
    int n=height.size();

    vector<int> next(n);

    //to find next smaller index for each element(right to left)
    next=NextSmaller(height,n);

    vector<int> prev(n);

    //to find previous smaller index for each element(left to right)
    prev=PrevSmaller(height,n);

    int area=INT_MIN;
    for(int i=0;i<n;i++){

        //height of paticular element
        int length=height[i];

        //if smallest(from ith point to last)
        if(next[i]==-1){

            //it takes whole the area
            next[i]=n;
        }

        //next smaller - previous smaller -1
        int breadth = next[i]-prev[i]-1;

        //area=length * breadth
        int newArea=length*breadth;

        //save the maximum
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