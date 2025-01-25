/*Minimum Cost Tree From Leaf Values
Given an array arr of positive integers, consider all binary trees such that:
    Each node has either 0 or 2 children;
    The values of arr correspond to the values of each leaf in an in-order traversal of the tree.
    The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree, respectively.
Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node. It is guaranteed this sum fits into a 32-bit integer.

A node is a leaf if and only if it has zero children.

Example 1:
Input: arr = [6,2,4]
Output: 32
Explanation: There are two possible trees shown.
The first has a non-leaf node sum 36, and the second has non-leaf node sum 32.

Example 2:
Input: arr = [4,11]
Output: 44
https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/description/*/
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr,map<pair<int,int>,int> &maxi){
    int n=arr.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));

    //iterate from last node to first
    for(int left=n-1;left>=0;left--){

        //iterate all the following nodes
        for(int right=left;right<n;right++){

            //leaf node
            if(left==right){
                continue;
            }else{
                int ans=INT_MAX;

                //all the possible subtree
                for(int i=left;i<right;i++){

                    //find product of 2 leaf node and sum it with the cost of non-leaf node of left subtree and right subtree
                    ans=min(ans,maxi[{left,i}]*maxi[{i+1,right}]+dp[left][i]+dp[i+1][right]);
                }
                dp[left][right]=ans;
            }
        }
    }
    return dp[0][n-1];
}

int mctFromLeafValues(vector<int>& arr) {
    int n=arr.size();

    //precomputing
    map<pair<int,int>,int> maxi;
    for(int i=0;i<arr.size();i++){
        maxi[{i,i}]=arr[i];

        //all possible range
        for(int j=i+1;j<arr.size();j++){

            //maximum value between range i,j
            maxi[{i,j}]=max(arr[j],maxi[{i,j-1}]);
        }
    }
    return solve(arr,maxi);        
}

int main() {
    // Test case 1
    vector<int> arr1 = {6, 2, 4};
    cout << "Output for [6, 2, 4]: " << mctFromLeafValues(arr1) << endl;

    // Test case 2
    vector<int> arr2 = {4, 11};
    cout << "Output for [4, 11]: " << mctFromLeafValues(arr2) << endl;

    // Additional test cases
    vector<int> arr3 = {1, 3, 2, 4};
    cout << "Output for [1, 3, 2, 4]: " << mctFromLeafValues(arr3) << endl;

    vector<int> arr4 = {7, 12, 8, 10};
    cout << "Output for [7, 12, 8, 10]: " << mctFromLeafValues(arr4) << endl;

    return 0;
}
