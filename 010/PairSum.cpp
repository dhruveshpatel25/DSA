#include<iostream>
using namespace std;

void PairSum(int arr[],int size,int S){
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(arr[i]+arr[j]==S){
                cout<<arr[i]<<" "<<arr[j]<<endl;
            }
        }
    }
}
int main(){
    int arr[5]={1,2,3,4,5};
    int S=5;
    PairSum(arr,5,5);
}