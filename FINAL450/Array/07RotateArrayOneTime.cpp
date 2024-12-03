#include<bits/stdc++.h>
using namespace std;
void Rotate(vector<int>& arr,int size){
    vector<int> ans(size);
    for(int i=0;i<size;i++){
        ans[(i+1)%size]=arr[i];
    }
    arr=ans;
}
int main(){
    int size;
    cout<<"Enter the size of array: ";
    cin>>size;
    vector<int> arr(size);
    cout<<"Enter the elements for array: ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    Rotate(arr,size);
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}