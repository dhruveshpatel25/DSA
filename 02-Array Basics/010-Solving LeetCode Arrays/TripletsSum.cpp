#include<iostream>
using namespace std;

void PairSum(int arr[],int size,int S){
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            for(int k=j+1;k<size;k++){
                if(arr[i]+arr[j]+arr[k]==S){
                    cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<endl;
                    break;
                }
            }
        }
    }
}
int main(){
    int arr[5]={1,2,3,4,5};
    int S=12;
    PairSum(arr,5,12);
}