#include<bits/stdc++.h>
using namespace std;

void MoveNegative(vector<int> &arr,int size){
    int left=0;
    int right=size-1;
    while(left<=right){
        if(arr[left]<0 && arr[right]<0){
            left++;
        }else if(arr[left]>0 && arr[right]<0){
            swap(arr[left],arr[right]);
            left++;
            right--;
        }else if(arr[left]<0 && arr[right]>0){
            left++;
            right--;
        }else{
            right--;
        }
    }
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
    MoveNegative(arr,size);
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}