/*Selection Sort
Selection sort is one of the sorting algorithms that works by repeatedly finding the minimum element from the unsorted part of the array and putting it at the beginning of the unsorted region of the array.

You are given an unsorted array consisting of N non-negative integers. Your task is to sort the array in non-decreasing order using the Selection Sort algorithm.
https://www.naukri.com/code360/problems/selection-sort_981162

Input: {2,3,5,4,1}
Output: 2 3 5 4 1 
        1 3 5 4 2 
        1 2 5 4 3 
        1 2 3 4 5 
        1 2 3 4 5 
        1 2 3 4 5*/
#include<iostream>
using namespace std;

//first sort the smallest element than continue to largest element
void SelectionSort(int arr[],int size){

    //iterate the array
    for(int i=0;i<size;i++){

        //make the first element of array as minimum
        int mini=i;

        //second iteration for ahead element
        for(int j=i+1;j<size;j++){

            //if he current element is less then 'mini' then make the element as mini
            if(arr[j]<=arr[mini]){
                mini=j;
            }
        }

        //just to understand how it works
        for(int i=0; i<size; i++){ 
            cout<<arr[i]<<" ";
        }
        cout<<endl;

        //swap the mini element and the first element
        swap(arr[mini],arr[i]);
    }
}

int main(){
    int arr[5]={2,3,5,4,1};
    int size=5;
    SelectionSort(arr,5);
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}