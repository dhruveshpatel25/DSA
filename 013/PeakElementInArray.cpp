#include<iostream>
using namespace std;

int PeakElement(int arr[],int size){
    int start=0;
    int end=size-1;
    while(start<end){
        int mid=start+((end-start)/2);
        if(arr[mid]<arr[mid+1]){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        return arr[start];
    }
}
int main(){
    int arr[5]={1,2,3,5,4};
    int result=PeakElement(arr,5);
    cout<<result;
}