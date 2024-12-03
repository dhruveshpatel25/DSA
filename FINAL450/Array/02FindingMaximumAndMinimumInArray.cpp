#include<bits/stdc++.h>
using namespace std;

int Maxi(vector<int> arr,int size){
    int maxi=INT_MIN;
    for(int i=0;i<size;i++){
        if(arr[i]>maxi){
            maxi=arr[i];
        }
    }
    return maxi;
}

int Mini(vector<int> arr,int size){
    int mini=INT_MAX;
    for(int i=0;i<size;i++){
        if(arr[i]<mini){
            mini=arr[i];
        }
    }
    return mini;
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
    cout<<"Maximum value of the array: "<<Maxi(arr,size)<<endl;
    cout<<"Minimum value of the array: "<<Mini(arr,size);
}