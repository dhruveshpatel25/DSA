/*Unique Number of Occurrences
Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.
https://leetcode.com/problems/unique-number-of-occurrences/description/*/
#include<iostream>
using namespace std;

bool FindUniqueOccurence(int arr[],int size){

    //count array to store the number in the array
    int count[100]={0};
    for(int i=0;i<size;i++){
        count[arr[i]]++;
    }

    //frequency array to count the number of times that number repeated
    int freq[100]={0};
    for(int i=0;i<100;i++){
        if(count[i]>0){
            //if the frequency is more then 2 then return false
            if(freq[count[i]]>0){
                return false;
            }

            //set 1 if freqency is 0
            freq[count[i]]=1;
        }
    }
    return true;
}
int main(){
    int arr[6]={1,2,2,3,3,3};
    bool result=FindUniqueOccurence(arr,6);
    if(result){
        cout<<"True";
    }else{
        cout<<"False";
    }
}