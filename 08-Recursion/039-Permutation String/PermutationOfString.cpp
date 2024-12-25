/*Permutations
Given an array nums of distinct integers, return all the possible permutations.You can return the answer in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:
Input: nums = [0,1]
Output: [[0,1],[1,0]]

Example 3:
Input: nums = [1]
Output: [[1]]
https://leetcode.com/problems/permutations/description/*/
#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int>& arr, int index, vector<vector<int>>& ans){

    //base case
    if(index>=arr.size()){
        ans.push_back(arr);
        return;
    }

    //iterate from first element
    for(int i= index ;i<arr.size();i++){

        //so other elements can be at index posiion
        swap(arr[index],arr[i]);

        //to change the rest of the array
        solve(arr,index+1,ans);

        //backtracking  
        swap(arr[i],arr[index]);
    }
}

vector<vector<int>> permutation(vector<int>& arr){

    //to store the answer
    vector<vector<int>> ans;
    int index=0;
    if(arr.size()==0){
        return ans;
    }
    solve(arr,index,ans);
    return ans;
}

int main(){
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> result = permutation(arr);
    
    for(const auto& perm : result){
        cout << "[ ";
        for(const auto& num : perm){
            cout << num << " ";
        }
        cout << "]" ;
    }

    return 0;
}