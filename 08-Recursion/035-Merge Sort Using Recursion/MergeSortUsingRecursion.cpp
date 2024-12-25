/*Merge Sort
Given a sequence of numbers ‘ARR’. Your task is to return a sorted sequence of ‘ARR’ in non-descending order with help of the merge sort algorithm.

Example :
Merge Sort Algorithm -
Merge sort is a Divide and Conquer based Algorithm. It divides the input array into two-parts, until the size of the input array is not ‘1’. In the return part, it will merge two sorted arrays a return a whole merged sorted array.
https://www.naukri.com/code360/problems/merge-sort_920442*/
#include<iostream>
using namespace std;

void merge(int arr[],int start,int end){

    //get the middle element of that subarray
    int mid=start+((end-start)/2);

    //length for temporary array so no overwriting
    //length for first subarray
    int len1=mid-start+1;

    //length for second subarray
    int len2=end-mid;

    //first temporary array
    int *first = new int[len1];

    //second temporary array
    int *second= new int[len2];

    //pointer at main array
    int mainindex=start;

    //put the first part in first temporary array(start-middle)
    for(int i=0;i<len1;i++){
        first[i]=arr[mainindex++];
    }

    //pointer after middle element
    mainindex=mid+1;

    //put the second part in second temporary array(middle-end)
    for(int i=0;i<len2;i++){
        second[i]=arr[mainindex++];
    }

    //merge the two temporary array

    //pointer on array 1
    int index1=0;

    //pointer on array 2
    int index2=0;

    //pointer on main array
    mainindex=start;

    //iterate till both array have a size
    while(index1<len1 && index2<len2){

        //check which element is smaller
        if(first[index1]<second[index2]){

            //if element in first temporary array is smaller enter in main array
            arr[mainindex++]=first[index1++];
        }else{

            //if element in second temporary array is smaller enter in main array
            arr[mainindex++]=second[index2++];
        }
    }

    //if only first temporary array is left
    while(index1<len1){

        //enter all first temporary array element
        arr[mainindex++]=first[index1++];
    }

    //if only second temporary array is left
    while(index2<len2){

        //enter all second temporary array element
        arr[mainindex++]=second[index2++];
    }

    //delete both temporary array
    delete []first;
    delete []second;
}

void mergesort(int arr[],int start,int end){

    //base case- if they cross each other return the array
    if(start>=end){
        return;
    }

    //find the middle element
    int mid=start+((end-start)/2);

    //recursivly call for left sub array
    mergesort(arr,start,mid);

    //recursivly call for right sub array                                                                                           
    mergesort(arr,mid+1,end);

    //now merge the split the array
    merge(arr,start,end);
}

int main(){
    int arr[6]={3,6,4,5,1,2};
    int size=6;
    mergesort(arr,0,5);
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}