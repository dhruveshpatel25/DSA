#include<iostream>
using namespace std;

bool issorted(int arr[], int size){

    //base case
    if(size==0 || size==1){
        return true;
    }

    //if the previous element is bigger meaning it is not sorted
    if(arr[0]>arr[1]){
        return false;
    }

    //recursivly call the next elements and remove previous element
    issorted(arr+1,size-1);
}

int main(){
    int arr[5]={1,2,3,4,5};
    bool result=issorted(arr,5);
    if(result){
        cout<<"The array is sorted";
    }else{
        cout<<"The array is not sorted";
    }
}