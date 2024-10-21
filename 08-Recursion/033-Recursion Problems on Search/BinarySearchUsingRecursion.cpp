#include<iostream>
using namespace std;

bool binarysearch(int arr[],int start,int end,int key){
    int mid=start+(end-start)/2;
    if(start>end){
        return false;
    }
    if(arr[mid]==key){
        return true;
    }
    if(arr[mid]<key){
        return binarysearch(arr,mid+1,end,key);
    }else{
        return binarysearch(arr,start,mid-1,key);
    }
}

int main(){
    int arr[5]={1,2,3,4,5};
    int key=2;
    bool result=binarysearch(arr,0,4,key);
    if(result){
        cout<<"The element is found";
    }else{
        cout<<"The element is not found";
    }
}