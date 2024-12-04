/*Find All Duplicates in an Array
Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears at most twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant auxiliary space, excluding the space needed to store the output
https://leetcode.com/problems/find-all-duplicates-in-an-array/description/*/
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int findAllDuplicates( vector<int> arr){
    unordered_set<int> seen;
    unordered_set<int> duplicates;
    for(int num:arr){
        //if the number exist in the array then add in duplicate array
        if(seen.find(num)!=seen.end()){
            duplicates.insert(num);
        }else{ //if the number does not exist add it to seen array
            seen.insert(num);
        }
    }
    //only print the duplicate part
    for(int num:duplicates){
        cout<<num<<" ";
    }
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 1, 2, 6, 7, 8, 3};
    findAllDuplicates(arr);
    return 0;
}