#include<iostream>
using namespace std;

bool Possible(int arr[],int size,int student,int mid){
    int StudentCount=1;
    int PageSum=0;
    for(int i=0; i<size ; i++){
        if(arr[i]+PageSum <= mid){
            PageSum+=arr[i];
        }else{
            StudentCount++;
            if(StudentCount>student || arr[i]> mid ){
                return false;
            }else{
                PageSum=arr[i];
            }
        }
    }
    return true;
}

int Allocate(int arr[],int size,int student){
    int start=0;
    int sum=0;
    for(int i=0; i<size; i++){
        sum= sum+arr[i];
    }
    int ans=0;
    int end=sum;
    while(start<=end){
        int mid = start+((end-start)/2);
        if(Possible(arr,size,student,mid)){
            ans=mid;
            end=mid-1;
        }else{
            start=mid+1;
        }
    }
    return ans;
}

int main(){
    int arr[5]={25,46,28,49,24};
    int students=4;
    cout<<Allocate(arr,5,4);
}