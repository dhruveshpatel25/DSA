/*Maximum Frequency Number
Ninja is given an array of integers that contain numbers in random order. He needs to write a program to find and return the number which occurs the maximum times in the given input. He needs your help to solve this problem.

If two or more elements contend for the maximum frequency, return the element which occurs in the array first i.e. whose index is lowest.

For example,

For 'arr' = [ 1, 2, 3, 1, 2]. you need to return 1.
https://www.naukri.com/code360/problems/maximum-frequency-number_920319?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar*/
#include<iostream>
#include<map>
#include<unordered_map>
#include<vector>
using namespace std;

int maximuFrequency(vector<int> &arr,int n){

    //map to store the count of the element
    unordered_map<int,int> count;

    //maximum frequency
    int maxfreq=0;

    //maximum element
    int maxans=0;

    for(int i=0;i<arr.size();i++){

        //increse the count of each array in map
        count[arr[i]]++;

        //update the value of the max frequency
        maxfreq=max(maxfreq,count[arr[i]]);
    }
    for(int i=0;i<arr.size();i++){

        //check whether the maximum frequency matches with the count
        if(maxfreq==count[arr[i]]){

            //if it store in the maxans
            maxans=arr[i];
        }
    }
    return maxans;
}

int main() {
    vector<int> arr = {1, 2, 2, 3, 3, 3, 3, 3, 4, 4, 4, 4};
    int n = arr.size();
    int maxFrequencyElement = maximuFrequency(arr, n);
    cout << "Element with maximum frequency: " << maxFrequencyElement << endl;
    return 0;
}
