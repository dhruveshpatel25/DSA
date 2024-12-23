/*Reverse String
Write a function that reverses a string. The input string is given as an array of characters s.
You must do this by modifying the input array in-place with O(1) extra memory.
Example 1:
Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]

Example 2:
Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
https://leetcode.com/problems/reverse-string/description/*/
#include<iostream>
#include<vector>
using namespace std;

void Reverse(vector<char>& arr){

    //start pointer
    int start=0;

    //end pointer
    int end=arr.size()-1;

    //iterate till they cross each other
    while(start<=end){

        //swap start and end pointer
        swap(arr[start++],arr[end--]);
    }
}
int main(){
    vector<char> arr;
    arr.push_back('D');
    arr.push_back('h');
    arr.push_back('r');
    arr.push_back('u');
    arr.push_back('v');
    arr.push_back('e');
    arr.push_back('s');
    arr.push_back('h');
    Reverse(arr);
    for(int k=0;k<arr.size();k++){
        cout<<arr[k]<<" ";
    }
}