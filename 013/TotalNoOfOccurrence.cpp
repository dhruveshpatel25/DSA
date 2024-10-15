#include<iostream>
using namespace std;
int LastOccurrence(int arr[],int size, int key){
    int start=0;
    int end=size-1;
    int ans=-1;
    while(start<=end){
        int mid= start+((end-start)/2);
        if(key==arr[mid]){
            ans=mid;
            start=mid+1;
        }else if(key>arr[mid]){
            start=mid+1;
        }else{
            end=mid-1;
        }
    }
    return ans;
}

int FirstOccurrence(int arr[],int size, int key){
    int start=0;
    int end=size-1;
    int ans=-1;
    while(start<=end){
        int mid= start+((end-start)/2);
        if(key==arr[mid]){
            ans=mid;
            end=mid-1;
        }else if(key>arr[mid]){
            start=mid+1;
        }else{
            end=mid-1;
        }
    }
    return ans;
}
int main(){
    int arr[9]={1,1,2,2,2,2,4,4,4};
    int result1=FirstOccurrence(arr,9,2);
    int result2=LastOccurrence(arr,9,2);
    int total;
    total=(result2-result1)+1;
    cout<<total;
}