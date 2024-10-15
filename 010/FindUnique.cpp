#include<iostream>
using namespace std;

int FindUnique(int arr[], int size){
    int ans=0;
    for(int i=0;i<size;i++){
        ans=ans^arr[i];
    }
    return ans;
}

int main(){
    int arr[5]={1,2,3,2,1};
    FindUnique(arr,5);
    int ans=FindUnique(arr,5);
    cout<<"The Unique Value is: "<<ans;
}