/*Quick Sort
ou are given an array of integers. You need to sort the array in ascending order using quick sort.
Quick sort is a divide and conquer algorithm in which we choose a pivot point and partition the array into two parts i.e, left and right. The left part contains the numbers smaller than the pivot element and the right part contains the numbers larger than the pivot element. Then we recursively sort the left and right parts of the array.

Example:
Let the array = [ 4, 2, 1, 5, 3 ]
Let pivot to be the rightmost number.
After the 1st level partitioning the array will be { 2, 1, 3, 4, 5 } as 3 was the pivot. 
After 2nd level partitioning the array will be { 1, 2, 3, 4, 5 } as 1 was the pivot for the left part and 5 was the pivot for the right part. 
Now our array is sorted and there is no need to divide it again.
https://www.naukri.com/code360/problems/quick-sort_983625*/
#include<iostream>
using namespace std;

int partition(int arr[], int start, int end){

    //pivot- element whose correct position is to be found
    int pivot=start;

    //position it has to be
    int count=0;

    //iterate array to find the position
    for(int i=start+1;i<=end;i++){

        //anytime when the current elements is small 
        if(arr[i]<=arr[pivot]){

            //add it to counter
            count++;
        }
    }

    //the new index of the pivot element
    int pivotindex= start+count;

    //swap it
    swap(arr[start],arr[pivotindex]);


    //start pointer
    int i=start;

    //end pointer
    int j=end;

    //iterate till they reach pivot
    while(i<pivotindex && j>pivotindex){

        //if element on right subarray is smaller
        if(arr[i]<arr[pivotindex]){

            //just move the pointer ahead
            i++;
        }

        //if element on the left subarray is bigger
        if(arr[j]>arr[pivotindex]){

            //just move the pointer ahead
            j--;
        }
        
        //if not
        else{

            //swap them
            swap(arr[i],arr[j]);
        }     
    }
}

void quicksort(int arr[], int start, int end){

    //base case- when they cross each other return the array
    if(start>=end){
        return;
    }

    //get the partition element from the array
    int p=partition(arr,start,end);

    //recursivly sort the first half before partition element
    quicksort(arr,start,p-1);

    //recursivly sort the second half after partition element
    quicksort(arr,p+1,end);
}

int main(){
    int arr[5]={2,4,3,5,1};
    int size=5;
    quicksort(arr,0,4);
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}