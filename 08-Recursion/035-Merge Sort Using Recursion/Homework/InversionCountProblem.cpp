/*Count Inversions
For a given integer array/list 'ARR' of size 'N' containing all distinct values, find the total number of 'Inversions' that may exist.

An inversion is defined for a pair of integers in the array/list when the following two conditions are met.

A pair ('ARR[i]', 'ARR[j]') is said to be an inversion when:

1. 'ARR[i] > 'ARR[j]' 
2. 'i' < 'j'

Where 'i' and 'j' denote the indices ranging from [0, 'N').
https://www.naukri.com/code360/problems/count-inversions_615*/
#include<iostream>
using namespace std;

//to count inversion
int count=0;

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

            //as all the remanining elements will be greater so add it to count
            count+=len1-index1;

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
    int arr[5]={2,5,1,3,4};
    int size=5;

    mergesort(arr,0,4);
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<count;
}