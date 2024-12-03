#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr,int start,int end){
    int pivot=start;
    int count=0;
    for(int i=start+1;i<=end;i++){
        if(arr[i]<=arr[pivot]){
            count++;
        }
    }
    int pivotIndex=start+count;
    swap(arr[pivot],arr[pivotIndex]);
    int i=start;
    int j=end;
    while(i<pivotIndex && j>pivotIndex){
        if(arr[i]<arr[pivotIndex]){
            i++;
        }
        if(arr[j]>arr[pivotIndex]){
            j--;
        }else{
            swap(arr[i],arr[j]);
        }
    }
    return pivotIndex;
}

vector<int> quicksort(vector<int>& arr,int start,int end){
    if(start>=end){
        return arr;
    }
    int p=partition(arr,start,end);
    quicksort(arr,start,p-1);
    quicksort(arr,p+1,end);
    return arr;
}

int KthMaximum(vector<int> arr,int size,int k){
    int start=0;
    int end=size-1;
    quicksort(arr,start,end);
    return arr[size-k];
}

int KthMinimum(vector<int> arr,int size,int k){
    int start=0;
    int end=size-1;
    quicksort(arr,start,end);
    return arr[k-1];
}

int main(){
    int size;
    cout<<"Enter the size of array: ";
    cin>>size;
    vector<int> arr(size);
    cout<<"Enter the elements: ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    int k;
    cout<<"Enter the value of k: ";
    cin>>k;
    cout<<"The "<<k<<"th maximum is: "<<KthMaximum(arr,size,k)<<endl;
    cout<<"The "<<k<<"th minimum is: "<<KthMinimum(arr,size,k)<<endl;
}