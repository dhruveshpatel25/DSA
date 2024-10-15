#include<iostream>
using namespace std;

void Sort(int arr[],int size){
    int i=0;
    int j=size-1;
    int k=0;
    while(k<=j){
        switch(arr[k]){
            case 0: swap(arr[i],arr[k]);
                    i++;
                    k++;
                    break;
            case 1: k++;
                    break;
            case 2: swap(arr[k],arr[j]);
                    j--;
                    break;
        }
    }
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[6]={2,1,2,0,1,0};
    Sort(arr,6);
}