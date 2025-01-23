/*Search In Rotated Sorted Array
You have been given a sorted array/list 'arr' consisting of ‘n’ elements. You are also given an integer ‘k’.
Now the array is rotated at some pivot point unknown to you.

For example, if 'arr' = [ 1, 3, 5, 7, 8], then after rotating 'arr' at index 3, the array will be 'arr' = [7, 8, 1, 3, 5].
Now, your task is to find the index at which ‘k’ is present in 'arr'.
Note :
1. If ‘k’ is not present in 'arr', then print -1.
2. There are no duplicate elements present in 'arr'. 
3. 'arr' can be rotated only in the right direction.

Example:
Input: 'arr' = [12, 15, 18, 2, 4] , 'k' = 2
Output: 3
Explanation:
If 'arr' = [12, 15, 18, 2, 4] and 'k' = 2, then the position at which 'k' is present in the array is 3 (0-indexed).
https://www.naukri.com/code360/problems/search-in-rotated-sorted-array_1082554*/
#include<iostream>
using namespace std;

//find the point where the array is rotated
int Pivot(int arr[], int size){

    //left pointer
    int start=0;

    //right pointer
    int end= size-1;

    //iterate till the left and right pointer dont cross
    while(start<=end){

        //get the middle value
        int mid= start+((end-start)/2);

        //move the left pointer to the right of the bigger middle element
        if(arr[mid]>arr[0]){
            start=mid+1;
        }

        //move the right pointer to the left of middle element
        else{
            end=mid-1;
        }
        
    }
    return start;
}

int BinarySearch(int arr[],int start, int end ,int key){

    //get the middle value
    int mid=start+(end-start)/2;

    //iterate till the left and right pointer dont cross
    while(start<=end){

        //if the middle value is the key element
        if(key==arr[mid]){
            return mid;
        }

        //if the key element is greater than the middle element
        if(key>arr[mid]){

            //move the left pointer to the right of middle element
            start=mid+1;
        }

        //if the key element is smaller than the middle element
        else{

            //move the right pointer to the left of middle element
            end=mid-1;
        }

        //update the middle element
        mid=start+(end-start)/2;
    }
    return -1;
}

int FindPosition(int arr[],int size,int k){

    //get the pivot element
    int pivot=Pivot(arr,size);

    //if the targeted element is in smaller sub array
    if (k >= arr[pivot] && k<=arr[size-1]){
        return BinarySearch(arr,pivot,size-1,k);
    }

    //if the targeted element is in larger sub array
    else{
        return BinarySearch(arr,0,pivot-1,k);
    }
}
int main(){
    int arr[] = {4, 5, 6, 7, 8, 9, 1, 2, 3};
    int key = 2;
    int size = sizeof(arr) / sizeof(arr[0]);

    int position = FindPosition(arr, size,key);

    if(position != -1){
        cout << "Element found at index " << position << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}