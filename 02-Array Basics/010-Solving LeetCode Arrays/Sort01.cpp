#include<iostream>
using namespace std;
void Sort(int arr[],int size){
    int i=0;
    int j=size-1;
    while(i<j){

        //if i pointer has 0 move ahead
        if(arr[i]==0){
            i++;

        //if j pointer has 1 move ahead (from back)
        }else if(arr[j]==1){
            j--;
        }

        //else swap
        else
        {
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[6]={0,1,0,1,1,0};
    Sort(arr,6);
}