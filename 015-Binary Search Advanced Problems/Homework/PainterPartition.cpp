#include<iostream>
using namespace std;

bool Possible(int arr[],int size, int painter,int mid){
    int PainterCount=1;
    int TimeSum=0;
    for(int i=0;i<size;i++){
        if(TimeSum+arr[i]<=mid){
            TimeSum+=arr[i];
        }else{
            PainterCount++;
            if(PainterCount>painter || arr[i]>mid){
                return false;
            }else{
                TimeSum=arr[i];
            }
        }
    }
    return true;
}

int Partition(int arr[],int size,int painter){
    int start=0;
    int sum=0;
    for(int i=0; i<size; i++){
        sum+=arr[i];
    }
    int end=sum;
    int ans=0;
    while(start<=end){
        int mid=start+((end-start)/2);
        if(Possible(arr,size,painter,mid)){
            ans=mid;
            end=mid-1;
        }else{
            start=mid+1;
        }
    } 
    return ans;   
}
int main(){
    int arr[6]={2,1,5,6,2,3};
    cout<<Partition(arr,6,2);
}