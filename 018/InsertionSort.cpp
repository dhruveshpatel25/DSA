#include<iostream>
using namespace std;

void InsertionSort(int arr[],int size){
    for(int i=1; i<size; i++){
        int temp=arr[i];
        int j=i-1;
        for(;j>=0;j--){
            if(arr[j]>temp){
                arr[j+1]=arr[j];
            }else{
                break;
            }
        }arr[j+1]=temp;
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