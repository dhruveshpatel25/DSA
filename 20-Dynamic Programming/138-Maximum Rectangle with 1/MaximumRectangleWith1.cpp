/*Max rectangle
Given a binary matrix mat[][] of size n * m. Find the maximum area of a rectangle formed only of 1s in the given matrix.

Examples:
Input: mat[][] = [[0, 1, 1, 0],
                [1, 1, 1, 1],
                [1, 1, 1, 1],
                [1, 1, 0, 0]]
Output: 8
Explanation: The largest rectangle with only 1’s is from (1, 0) to (2, 3) which is
[1, 1, 1, 1]
[1, 1, 1, 1]
and area is 4 *2 = 8.

Input: mat[][] = [[0, 1, 1],
                [1, 1, 1],
                [0, 1, 1]]
Output: 6
Explanation: The largest rectangle with only 1’s is from (0, 1) to (2, 2) which is
[1, 1]
[1, 1]
[1, 1]
https://www.geeksforgeeks.org/problems/max-rectangle/1*/
#include<iostream>
#include<stack>
#include<climits>
#include<vector>
using namespace std;

const int MAX = 100;

vector<int> NextSmaller(int* arr,int n){

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

vector<int> PrevSmaller(int* arr,int n){

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


int LargestRectangleArea(int* height,int n){

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

int maximumRectangle(int M[MAX][MAX], int n,int m){

    //first row
    int area = LargestRectangleArea(M[0],m);
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){

            //if not zero add the height with previous
            if(M[i][j]!=0){
                M[i][j]=M[i][j]+M[i-1][j];
            }else{

                //if 0 meaning the height above is irrelevant
                M[i][j]=0;
            }
        }

        //maximum area
        area=max(area,LargestRectangleArea(M[i],m));
    }
    return area;
}

int main() {
    int n = 4, m = 4;
    int M[MAX][MAX] = {
        {1, 0, 1, 0},
        {1, 1, 1, 1},
        {1, 1, 1, 0},
        {1, 1, 1, 1}
    };
    int maxRectArea = maximumRectangle(M, n, m);
    cout << "Maximum rectangular area: " << maxRectArea << endl;

   return 0;
}