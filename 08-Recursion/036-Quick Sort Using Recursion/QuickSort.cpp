#include<iostream>
using namespace std;

int partition(int arr[], int start, int end){
    int pivot=start;
    int count=0;
    for(int i=start+1;i<=end;i++){
        if(arr[i]<=arr[pivot]){
            count++;
        }
    }
    int pivotindex= start+count;
    swap(arr[start],arr[pivotindex]);
    int i=start;
    int j=end;

    while(i<pivotindex && j>pivotindex){
        if(arr[i]<arr[pivotindex]){
            i++;
        }
        if(arr[j]>arr[pivotindex]){
            j--;
        }else{
            swap(arr[i],arr[j]);
        }     
    }
}

void quicksort(int arr[], int start, int end){
    if(start>=end){
        return;
    }
    int p=partition(arr,start,end);
    quicksort(arr,start,p-1);
    quicksort(arr,p+1,end);
}

int main(){
    int arr[5]={2,4,3,5,1};
    int size=5;
    quicksort(arr,0,4);
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}