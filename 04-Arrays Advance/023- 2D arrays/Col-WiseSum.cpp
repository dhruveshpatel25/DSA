/*1 2 3
  4 5 6
  7 8 9*/
#include<iostream>
using namespace std;

void ColSum(int arr[][3],int size1, int size2){

    //iterate the index row-wise
    for(int j=0; j<size2;j++){
        int sum=0;

        //iterate the complete column
        for(int i=0;i<size1;i++){
            sum=sum+arr[i][j];
        }
        cout<<sum<<" ";
    }
}

int main(){
    int arr[3][3]={1,2,3,4,5,6,7,8,9};
    ColSum(arr,3,3);
}