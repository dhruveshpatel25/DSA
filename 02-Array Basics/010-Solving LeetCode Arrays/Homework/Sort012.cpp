/*Sort 0 1 2
You have been given an integer array/list(ARR) of size 'N'. It only contains 0s, 1s and 2s. Write a solution to sort this array/list.

Note :
Try to solve the problem in 'Single Scan'. ' Single Scan' refers to iterating over the array/list just once or to put it in other words, you will be visiting each element in the array/list just once.
https://www.naukri.com/code360/problems/sort-0-1-2_631055?source=youtube&campaign=LoveBabbar_Codestudiovideo1&utm_source=youtube&utm_medium=affiliate&utm_campaign=LoveBabbar_Codestudiovideo1*/
#include<iostream>
using namespace std;

void Sort(int arr[],int size){
    int i=0;
    int j=size-1;
    int k=0;
    while(k<=j){
        switch(arr[k]){

            //if 0 then swap it with the i pointer
            case 0: swap(arr[i],arr[k]);
                    i++;
                    k++;
                    break;

            //if 1 then just move the k pointer
            case 1: k++;
                    break;

            //if 2 then swap with j pointer
            case 2: swap(arr[k],arr[j]);
                    j--;
                    break;
        }
    }
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[6]={2,1,2,0,1,0};
    Sort(arr,6);
}