#include<iostream>
#include<climits>
using namespace std;

int RowSum(int arr[][3],int size1, int size2){
    int maxi=INT_MIN;
    int index=0;
    for(int i=0; i<size1;i++){
        int sum=0;
        for(int j=0;j<size2;j++){
            sum=sum+arr[i][j];
        }
        if(sum>maxi){
            maxi=sum;
            index=i;
        }     
    }
    return index;
}

int main(){
    int arr[3][3]={1,2,3,4,5,6,7,8,9};
    cout<<RowSum(arr,3,3);
}