#include<bits/stdc++.h>
using namespace std;

void ReverseArray(vector<int> &arr,int size){
    int left=0;
    int right=size-1;
    while(left<=right){
        swap(arr[left++],arr[right--]);
    }
    
}

int main(){
    int size;
    cout<<"Enter the size of array: ";
    cin>>size;
    vector<int>arr1(size);
    cout<<"Enter the array:";
    for(int i=0;i<size;i++){
        cin>>arr1[i];
    }
    ReverseArray(arr1,size);
    for(int i=0;i<size;i++){
        cout<<arr1[i]<<" ";
    }
    return 0;
}