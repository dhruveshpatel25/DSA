/*1 2 3
  4 5 6
  7 8 9*/
#include<iostream>
using namespace std;

void RowSum(int arr[][3],int size1, int size2){

    //iterate the index column-wise
    for(int i=0; i<size1;i++){
        int sum=0;

        //iterate the complete row
        for(int j=0;j<size2;j++){
            sum=sum+arr[i][j];
        }
        cout<<sum<<" ";
    }
}

int main(){
    int arr[3][3]={1,2,3,4,5,6,7,8,9};
    RowSum(arr,3,3);
}