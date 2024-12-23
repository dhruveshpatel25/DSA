/*First and Last Position of an Element In Sorted Array
Problem statement
You have been given a sorted array/list 'arr' consisting of ‘n’ elements. You are also given an integer ‘k’.
Now, your task is to find the first and last occurrence of ‘k’ in 'arr'.
Note :
1. If ‘k’ is not present in the array, then the first and the last occurrence will be -1. 
2. 'arr' may contain duplicate elements.

Example:
Input: 'arr' = [0,1,1,5] , 'k' = 1
Output: 1 2
Explanation:
If 'arr' = [0, 1, 1, 5] and 'k' = 1, then the first and last occurrence of 1 will be 1(0 - indexed) and 2.
https://www.naukri.com/code360/problems/first-and-last-position-of-an-element-in-sorted-array_1082549*/
#include<iostream>
using namespace std;
int LastOccurrence(int arr[],int size, int key){

    //left pointer
    int start=0;

    //right pointer
    int end=size-1;

    //to store the value
    int ans=-1;

    //iterate till the left and right pointer dont cross
    while(start<=end){

        //get the middle value
        int mid= start+((end-start)/2);

        //if the middle value is the key element
        if(key==arr[mid]){

            //store that answer
            ans=mid;

            //move the left pointer to check for more value
            start=mid+1;
        }
        //if the key element is greater than the middle element
        else if(key>arr[mid]){

            //move the left pointer to the right of middle element
            start=mid+1;
        }
        //if the key element is smaller than the middle element
        else{

            //move the right pointer to the left of middle element
            end=mid-1;
        }
    }
    return ans;
}

int FirstOccurrence(int arr[],int size, int key){

    //left pointer
    int start=0;

    //right pointer
    int end=size-1;

    //to store the value
    int ans=-1;

    //iterate till the left and right pointer dont cross
    while(start<=end){

        //get the middle value
        int mid= start+((end-start)/2);

        //if the middle value is the key element
        if(key==arr[mid]){

            //store that answer
            ans=mid;

            //move the right pointer to check for more values
            end=mid-1;
        }
        //if the key element is greater than the middle element
        else if(key>arr[mid]){

            //move the left pointer to the right of middle element
            start=mid+1;
        }
        //if the key element is smaller than the middle element
        else{

            //move the right pointer to the left of middle element
            end=mid-1;
        }
    }
    return ans;
}
int main(){
    int arr[9]={1,1,2,2,2,2,4,4,4};
    int result1=FirstOccurrence(arr,9,2);
    int result2=LastOccurrence(arr,9,2);
    if (result1!= -1) {
        cout << "The First Occurrence of is at index " <<result1 << endl;
    } else {
        cout << "The Key does not exist" << endl;
    }

    if (result2!= -1) {
        cout << "The Last Occurrence of is at index " << result2 << endl;
    } else {
        cout << "The Key does not exist" << endl;
    }
}