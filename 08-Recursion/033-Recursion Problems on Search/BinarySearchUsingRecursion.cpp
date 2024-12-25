/*Binary Search
You are given an integer array 'A' of size 'N', sorted in non-decreasing order. You are also given an integer 'target'. Your task is to write a function to search for 'target' in the array 'A'. If it exists, return its index in 0-based indexing. If 'target' is not present in the array 'A', return -1.
https://www.naukri.com/code360/problems/binary-search_972*/
#include<iostream>
using namespace std;

bool binarysearch(int arr[],int start,int end,int key){

    //get the mid value
    int mid=start+(end-start)/2;

    //when start and end pointer cross each other return false as element was not found
    if(start>end){
        return false;
    }

    //if the mid element is key
    if(arr[mid]==key){
        return true;
    }

    //recursvily search after middle element
    if(arr[mid]<key){
        return binarysearch(arr,mid+1,end,key);
    }
    
    //recursivly search before middle element
    else{
        return binarysearch(arr,start,mid-1,key);
    }
}

int main(){
    int arr[5]={1,2,3,4,5};
    int key=2;
    bool result=binarysearch(arr,0,4,key);
    if(result){
        cout<<"The element is found";
    }else{
        cout<<"The element is not found";
    }
}