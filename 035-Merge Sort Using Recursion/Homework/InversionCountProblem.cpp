#include<iostream>
using namespace std;

int count=0;

void merge(int arr[],int start,int end){
    int mid=start+((end-start)/2);

    int len1=mid-start+1;
    int len2=end-mid;

    int *first = new int[len1];
    int *second= new int[len2];

    int mainindex=start;
    for(int i=0;i<len1;i++){
        first[i]=arr[mainindex++];
    }

    mainindex=mid+1;
    for(int i=0;i<len2;i++){
        second[i]=arr[mainindex++];
    }
    int index1=0;
    int index2=0;
    mainindex=start;
    while(index1<len1 && index2<len2){
        if(first[index1]<second[index2]){
            arr[mainindex++]=first[index1++];
        }else{
            count+=len1-index1;
            arr[mainindex++]=second[index2++];
        }
    }
    while(index1<len1){
        arr[mainindex++]=first[index1++];
    }
    while(index2<len2){
        arr[mainindex++]=second[index2++];
    }
    delete []first;
    delete []second;
}

void mergesort(int arr[],int start,int end){
    if(start>=end){
        return;
    }
    int mid=start+((end-start)/2);
    mergesort(arr,start,mid);
    mergesort(arr,mid+1,end);
    merge(arr,start,end);
}

int main(){
    int arr[6]={3,6,4,5,1,2};
    int size=6;

    mergesort(arr,0,5);
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<count;
}