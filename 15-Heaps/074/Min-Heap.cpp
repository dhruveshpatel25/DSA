#include<iostream>
using namespace std;

void heapify(int arr[],int size,int index){
    int smallest=index;
    int leftindex=2*index;
    int rightindex=2*index+1;

    if(leftindex<size && arr[smallest]>arr[leftindex]){
        smallest=leftindex;
    }
    else if(rightindex<size && arr[smallest]>arr[rightindex]){
        smallest=rightindex;
    }

    if(smallest!=index){
        swap(arr[smallest],arr[index]);
        heapify(arr,size,smallest);
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