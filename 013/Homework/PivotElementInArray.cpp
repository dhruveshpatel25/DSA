#include<iostream>
using namespace std;

int Pivot(int arr[], int size){
    int start=0;
    int end= size-1;
    while(start<=end){
        int mid= start+((end-start)/2);
        if(arr[mid]>arr[0]){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return start;
}
int main(){
    int arr[5]={3,4,5,1,2};
    int result= Pivot(arr,5);
    cout<<"The index at which Pivot took place is "<<result;    
}