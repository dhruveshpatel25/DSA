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

vector<int> PrevSmaller(int* arr,int n){

    stack<int> stk;
    stk.push(-1);
    vector<int> ans(n);

    for(int i=0;i<n;i++){
        int curr=arr[i];
        while(stk.top()!=-1 && arr[stk.top()]>=curr){
            stk.pop();
        }
        ans[i]=stk.top();
        stk.push(i);
    }
    return ans;
}

int LargestRectangleArea(int* height,int n){
    vector<int> next(n);
    next=NextSmaller(height,n);

    vector<int> prev(n);
    prev=PrevSmaller(height,n);

    int area=0;
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

int maximumRectangle(int M[MAX][MAX], int n,int m){
    int area = LargestRectangleArea(M[0],m);
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            if(M[i][j]!=0){
                M[i][j]=M[i][j]+M[i-1][j];
            }else{
                M[i][j]=0;
            }
        }
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