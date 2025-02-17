#include<iostream>
using namespace std;

void heapify(int arr[],int size,int index){
    int largest=index;
    int leftindex=2*index;
    int rightindex=2*index+1;

    //check if the left index in inside the count and then compare with largest value
    //if it is larger then swap
    if(leftindex<size && arr[largest]<arr[leftindex]){
        largest=leftindex;
    }

    //check if the right index in inside the count and then compare with largest value
    //if it is larger then swap
    if(rightindex<size && arr[largest]<arr[rightindex]){
        largest=rightindex;
    }

    //if there is update swap the largest with the indexed value and then recursivly call for heapify
    if(largest!=index){
        swap(arr[largest],arr[index]);
        heapify(arr,size,largest);
    }
}

int main(){
    int arr[6]={-1,54,53,55,52,50};
    int size=5;
    for(int i=size/2;i>0;i--){
        heapify(arr,size,i);
    }
    for(int i=1;i<=size;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}