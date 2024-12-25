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

vector<vector<int>> subset(vector<int>& arr){

    //size of the string
    int size=arr.size();

    //no.of subset by using formula 2^n
    int subsetcounts=(1<<size);

    //storing the answer
    vector<vector<int>> ans;

    //iterate through all the subset
    for(int mask=0;mask<subsetcounts;mask++){

        //for current subsequence
        vector<int>subset;

        //iterate through the complete array
        for(int i=0;i<size;i++){

            //check whether to include the current element or not
            //so if mask is 000 so dont include
            //if 001 include last element
            //if 011 include second and last element
            if((mask&(1<<i))!=0){

                //push back the current element
                subset.push_back(arr[i]);
            }
        }

        //push all the subset to answer
        ans.push_back(subset);
    }
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