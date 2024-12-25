/*Subsets
Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:
Input: nums = [0]
Output: [[],[0]]
https://leetcode.com/problems/subsets/description/*/
#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int>& arr,vector<int> output,int index, vector<vector<int>>& ans){
    //base case-push all the outputs in answer vector
    if(index >= arr.size()){
        ans.push_back(output);
        return;
    }

    //recusivly call by excluding current element
    solve(arr,output,index+1,ans);
    
    //get the element
    int element = arr[index];

    //push the element
    output.push_back(element);

    //recursivly call by including current element
    solve(arr,output,index+1,ans);
}

vector<vector<int>> subset(vector<int>& arr){

    //store the complete answer
    vector<vector<int>> ans;

    //store the partial answer
    vector<int> output;
    int index=0;
    solve(arr,output,index,ans);
    return ans;
}

int main(){
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    vector<vector<int>> result = subset(arr);
    for (const auto& subset : result) {
        cout << "[ ";
        for (const auto& num : subset) {
            cout << num << " ";
        }
        cout << "]" ;
    }
}