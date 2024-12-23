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
void BubbleSort(int arr[],int size){

    //first iteration
    for(int i=0;i<size;i++){

        //for checking if it is swapped or not for the iteration
        bool swapped = false;

        //second iteration
        for(int j=0;j<size;j++){

            //if the current element is greater than the next element 
            if(arr[j]>arr[j+1]){

                //swap the elements
                swap(arr[j],arr[j+1]);
                swapped=true;
            }
        }
        if(swapped==false){
            break;
        }

        //just to understand how it works
        for(int i=0; i<size; i++){ 
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int arr[5]={2,3,5,4,1};
    int size=5;
    BubbleSort(arr,5);
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}