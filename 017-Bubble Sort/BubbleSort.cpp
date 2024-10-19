#include<iostream>
using namespace std;

void BubbleSort(int arr[],int size){
    for(int i=0;i<size;i++){
        bool swapped = false;
        for(int j=0;j<size;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped=true;
            }
        }
        if(swapped==false){
            break;
        }
        /*for(int i=0; i<size; i++){ just to understand how it works
            cout<<arr[i]<<" ";
        }
        cout<<endl;*/
    }
}

int main(){
    int arr[5]={2,3,5,4,1};
    int size=5;
    BubbleSort(arr,5);
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}