#include<iostream>
using namespace std;

int Reverse(int arr[], int size){
    int start=0;
    int end=size-1;
    while(start<=end){

        //swap with the last number and then move
        swap(arr[start],arr[end]);
        start++;
        end--;
    } 
}

int PrintArray(int arr[], int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[5]={1,2,3,4,5};
    Reverse(arr,5);
    PrintArray(arr,5);
}