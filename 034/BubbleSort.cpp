#include<iostream>
using namespace std;

void bubblesort(int arr[],int size){
    if(size==1){
        return ;
    }
    for(int i=0;i<size;i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
    return bubblesort(arr,size-1);
}

int main(){
    int arr[5]={2,4,5,3,1};
    int size=5;
    bubblesort(arr,5);
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}