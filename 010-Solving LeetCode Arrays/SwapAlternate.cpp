#include<iostream>
using namespace std;

int SwapAlternate(int arr[], int size){
    for(int i=0;i<size;i+=2)
    if(i+1<size){
        swap(arr[i],arr[i+1]);
    }
}

void PrintArray(int arr[], int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[5]={1,2,3,4,5};
    SwapAlternate(arr,5);
    PrintArray(arr,5);
}