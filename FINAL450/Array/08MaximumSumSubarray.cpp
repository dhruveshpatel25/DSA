#include<bits/stdc++.h>
using namespace std;

int MaximumSumSubarray(vector<int> &arr,int size){
    int sum=0;
    int maxi=INT_MIN;
    for(int i=0;i<size;i++){
        sum=sum+arr[i];
        maxi=max(maxi,sum);
        if(sum<0){
            sum=0;
        }
    }
    return maxi;
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
    int sum = MaximumSumSubarray(arr,size);
    cout<<sum;
}