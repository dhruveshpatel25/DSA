#include<iostream>
using namespace std;

void SelectionSort(int arr[],int size){
    for(int i=0;i<size;i++){
        int mini=i;
        for(int j=i+1;j<size;j++){
            if(arr[j]<=arr[mini]){
                mini=j;
            }
        }
        /*for(int i=0; i<size; i++){ just to understand how it works
            cout<<arr[i]<<" ";
        }
        cout<<endl;*/
        swap(arr[mini],arr[i]);
    }
}

int main(){
    int arr[5]={2,3,5,4,1};
    int size=5;
    SelectionSort(arr,5);
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}