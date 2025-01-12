/*Russian Doll Envelopes
You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.
One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.
Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).
Note: You cannot rotate an envelope.

Example 1:
Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
Output: 3
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).

Example 2:
Input: envelopes = [[1,1],[1,1],[1,1]]
Output: 1 
https://leetcode.com/problems/russian-doll-envelopes/description/*/
#include<bits/stdc++.h>
using namespace std;

bool cmp(vector<int>& a,vector<int>& b){
    if(a[0]==b[0]){
        return a[1]>b[1];
    }
    return a[0]<b[0];
}

int solve(vector<vector<int>>& arr,int n){

    //if size is 0
    if(n==0){
        return 0;
    }

    //to store answer
    vector<int> ans;

    //width height
    int value=arr[0][1];

    //store the first element
    ans.push_back(value);

    //iterate the array
    for(int i=1;i<n;i++){

        //check for all the height
        if(arr[i][1]>ans.back()){

            //if height greater than last element of answer array put in answer
            ans.push_back(arr[i][1]);
        }else{

            //if smaller then check for its position in array 
            int index=lower_bound(ans.begin(),ans.end(),arr[i][1])-ans.begin();

            //erase the old element and put this new value
            ans[index]=arr[i][1];
        }
    }
    return ans.size();
}

int longestSubsequence(vector<vector<int>>& arr) {
    int n=arr.size();
    sort(arr.begin(),arr.end(),cmp);
    return solve(arr,n);
}

int main() {
    // Input test cases
    vector<vector<int>> envelopes1 = {{5, 4}, {6, 4}, {6, 7}, {2, 3}};
    vector<vector<int>> envelopes2 = {{1, 1}, {1, 1}, {1, 1}};

    // Test case 1
    cout << "Maximum number of Russian Doll Envelopes: "
         << longestSubsequence(envelopes1) << endl;

    // Test case 2
    cout << "Maximum number of Russian Doll Envelopes: "
         << longestSubsequence(envelopes2) << endl;

    return 0;
}
