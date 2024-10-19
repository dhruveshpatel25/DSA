#include<iostream>
using namespace std;

int sumofarray(int arr[], int size){
    int sum=0;
    if(size==0){
        return sum;
    }
    sum += arr[0];
    return sum + sumofarray(arr+1,size-1);
    
}

int main(){
    int arr[5]={1,2,3,4,5};
    int result=sumofarray(arr,5);
    cout<<result;
}