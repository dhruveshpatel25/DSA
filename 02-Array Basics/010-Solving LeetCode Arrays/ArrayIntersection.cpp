/*Intersection Of Two Sorted Arrays
You are given two arrays 'A' and 'B' of size 'N' and 'M' respectively. Both these arrays are sorted in non-decreasing order. You have to find the intersection of these two arrays.

Intersection of two arrays is an array that consists of all the common elements occurring in both arrays.

Note :
1. The length of each array is greater than zero.
2. Both the arrays are sorted in non-decreasing order.
3. The output should be in the order of elements that occur in the original arrays.
4. If there is no intersection present then return an empty array.
https://www.naukri.com/code360/problems/intersection-of-2-arrays_1082149?source=youtube&campaign=love_babbar_codestudio1&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio1*/
#include<iostream>
#include<climits>
using namespace std;

int Intersection(int arr1[],int arr2[],int size1, int size2){
    for(int i=0; i<size1;i++){

        //take the particular elemnt from array
        int element=arr1[i];
        for(int j=0;j<size2;j++){

            //check if it matches the in second array
            if(element==arr2[j]){
                cout<<element<<" ";

                //replace it in second to avoid duplication
                arr2[j]=INT_MIN;
                break;
            }
        }
    }
}
int main(){
    int arr1[6]={1,2,2,2,3,4};
    int arr2[4]={2,2,3,3};
    Intersection(arr1,arr2,6,4);
}