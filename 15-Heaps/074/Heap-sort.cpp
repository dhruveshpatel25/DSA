#include<iostream>
using namespace std;

void heapify(int arr[],int size,int index){
    int largest=index;
    int leftindex=2*index;
    int rightindex=2*index+1;

    if(leftindex<=size && arr[largest]<arr[leftindex]){
        largest=leftindex;
    }
    if(rightindex<=size && arr[largest]<arr[rightindex]){
        largest=rightindex;
    }

    if(largest!=index){
        swap(arr[largest],arr[index]);
        heapify(arr,size,largest);
    }
}

void heapSort(int arr[],int n){
    int size=n;
    while(size>1){
        swap(arr[1],arr[size]);
        size--;
        heapify(arr,size,1);
    }
}

int main(){
    int arr[6]={-1,54,53,55,52,50};
    int size=5;
    for(int i=size/2;i>0;i--){
        heapify(arr,size,i);
    }
    heapSort(arr,size);
    for(int i=1;i<=size;i++){
        cout<<arr[i]<<" ";
    }
}