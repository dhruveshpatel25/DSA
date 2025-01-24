/*Sum of minimum and maximum elements of all subarrays of size k.
Given an array of both positive and negative integers, the task is to compute sum of minimum and maximum elements of all sub-array of size k.

Examples: 

Input : arr[] = {2, 5, -1, 7, -3, -1, -2}  
        K = 4
Output : 18
Explanation : Subarrays of size 4 are : 
     {2, 5, -1, 7},   min + max = -1 + 7 = 6
     {5, -1, 7, -3},  min + max = -3 + 7 = 4      
     {-1, 7, -3, -1}, min + max = -3 + 7 = 4
     {7, -3, -1, -2}, min + max = -3 + 7 = 4   
     
     Missing sub arrays - 
     
     {2, -1, 7, -3}
     {2, 7, -3, -1}
     {2, -3, -1, -2}
     {5, 7, -3, -1}
     {5, -3, -1, -2}
     and few more -- why these were not considered??
     Considering missing arrays result coming as 27
     
     Sum of all min & max = 6 + 4 + 4 + 4 = 18
https://www.geeksforgeeks.org/sum-minimum-maximum-elements-subarrays-size-k/*/
#include<iostream>
#include<queue>
using namespace std;

int sumOfMaxandMin(int *arr,int size,int windowsize){
    deque<int> maxi(windowsize);
    deque<int> mini(windowsize);

    //addition of first windowsize 
    for(int i=0;i<windowsize;i++){

        //loop till you get maximum value
        while(!maxi.empty() && arr[maxi.back()]<=arr[i]){
            maxi.pop_back();
        }

        //loop till you get minimum value
        while(!mini.empty() && arr[mini.back()]>=arr[i]){
            mini.pop_back();
        }

        //push back index value of current index
        maxi.push_back(i);
        mini.push_back(i);
    }

    int ans=0;
    ans += arr[maxi.front()] + arr[mini.front()];

    for(int i=windowsize;i<size;i++){
        while(!maxi.empty() && i-maxi.front()>=windowsize){
            maxi.pop_front();
        }

        while(!mini.empty() && i-mini.front()>=windowsize){
            mini.pop_front();
        }

        while(!maxi.empty() && arr[maxi.back()]<=arr[i]){
            maxi.pop_back();
        }

        while(!mini.empty() && arr[mini.back()]>=arr[i]){
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);

        ans+= arr[maxi.front()]+arr[mini.front()];
    } 
    return ans;
}

int main() {
    int arr[7] = {2, 5, -1, 7, -3, -1, -2};
    int k = 4;
    cout << sumOfMaxandMin(arr, 7, k) << endl;
    return 0;
}