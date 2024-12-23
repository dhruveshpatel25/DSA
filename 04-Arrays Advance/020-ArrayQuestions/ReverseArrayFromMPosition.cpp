/*Reverse The Array
Given an array/list 'ARR' of integers and a position ‘M’. You have to reverse the array after that position.

Example:
We have an array ARR = {1, 2, 3, 4, 5, 6} and M = 3 , considering 0 
based indexing so the subarray {5, 6} will be reversed and our 
output array will be {1, 2, 3, 4, 6, 5}.
https://www.naukri.com/code360/problems/reverse-the-array_1262298*/
#include<iostream>
#include<vector>
using namespace std;

void Reverse(vector<int>& arr, int m){

    //start pointer from mth position
    int start=m+1;

    //end pointer from the last position in array
    int end=arr.size()-1;

    //iterate till they cross each other
    while(start<=end){

        //swap them
        swap(arr[start],arr[end]);

        //move the start pointer ahead
        start++;

        //move the end pointer behind
        end--;
    }
}

int main(){
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    int m=1;
    Reverse(arr,m);

    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}