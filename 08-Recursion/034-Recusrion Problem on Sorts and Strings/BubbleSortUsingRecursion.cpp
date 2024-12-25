/*Bubble Sort
Bubble Sort is one of the sorting algorithms that works by repeatedly swapping the adjacent elements of the array if they are not in sorted order.

You are given an unsorted array consisting of N non-negative integers. Your task is to sort the array in non-decreasing order using the Bubble Sort algorithm.
https://www.naukri.com/code360/problems/bubble-sort_980524
Input: {2,3,5,4,1}
Output: 2 3 4 1 5 
        2 3 1 4 5
        2 1 3 4 5
        1 2 3 4 5
        1 2 3 4 5*/
#include<iostream>
using namespace std;

//first sort the largest element than the smallest element
void bubblesort(int arr[],int size){
    if(size==1){
        return ;
    }

    //iterate the whole array
    for(int i=0;i<size;i++){

        //check whether the current element is bigger then next element
        if(arr[i]>arr[i+1]){

            //if current element bigger swap it
            swap(arr[i],arr[i+1]);
        }
    }

    //recursivly call for by permanently fixing the large element at last
    return bubblesort(arr,size-1);
}

int main(){
    int arr[5]={2,4,5,3,1};
    int size=5;
    bubblesort(arr,5);
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}