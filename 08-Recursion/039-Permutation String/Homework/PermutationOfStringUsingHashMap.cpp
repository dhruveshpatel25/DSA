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
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Helper function to generate permutations
void generatePermutations(vector<int> &nums, unordered_map<int, bool> &visited, vector<int> &current, vector<vector<int>> &result) {
    // Base case: if the current permutation has all the elements
    if (current.size() == nums.size()) {
        result.push_back(current);
        return;
    }

    // Iterate through the array
    for (int i = 0; i < nums.size(); i++) {
        // If the element is already used, skip it
        if (visited[nums[i]]){
            continue;
        }
        
        // Mark the element as visited
        visited[nums[i]] = true;
        current.push_back(nums[i]);

        // Recursively generate permutations for the remaining elements
        generatePermutations(nums, visited, current, result);

        // Backtrack: undo the changes for the next iteration
        current.pop_back();
        visited[nums[i]] = false;
    }
}

vector<vector<int>> permute(vector<int> &nums) {

    // To store all permutations
    vector<vector<int>> result;  

    // To store the current permutation  
    vector<int> current;         

    // Hashmap to track visited elements 
    unordered_map<int, bool> visited; 


    // Initialize the hashmap with all elements marked as unvisited
    for (int num : nums) {
        visited[num] = false;
    }

    // Generate permutations
    generatePermutations(nums, visited, current, result);

    return result;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> permutations = permute(nums);

    cout << "Permutations:" << endl;
    for (auto &permutation : permutations) {
        cout << "[";
        for (int num : permutation) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
