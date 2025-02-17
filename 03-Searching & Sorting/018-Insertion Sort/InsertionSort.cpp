/*Insertion Sort
You are given ‘N’ integers in the form of an array ‘ARR’. Print the sorted array using the insertion sort.

Note :
No need to return anything. You should sort the array in-place.
For example :
Let ‘ARR’ be: [1, 4, 2]
The sorted array will be: [1, 2, 4].
https://www.naukri.com/code360/problems/insertion-sort_3155179
Input: {2,3,5,4,1}
Output: 2 3 1 5 4 
        1 2 3 5 4 
        1 2 3 5 4 
        1 2 3 4 5 
        1 2 3 4 5*/
#include<iostream>
using namespace std;

//sort smaller no.of elements to the whole array
void InsertionSort(int arr[],int size){

    //iterate for the second element to last element
    for(int i=1; i<size; i++){

        //save the element
        int temp=arr[i];

        //one element ahead
        int j=i-1;

        //iterate backward for paticular element
        for(;j>=0;j--){

            //if the ahead element is greater
            if(arr[j]>temp){

                //move it behind
                arr[j+1]=arr[j];
            }
            
            //if it is sorted
            else{

                //break from the loop
                break;
            }
        }

        //now put the element in correct place
        arr[j+1]=temp;

        //just to understand how it works
        for(int i=0; i<size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int arr[5]={2,3,1,5,4};
    int size=5;
    InsertionSort(arr,5);
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}