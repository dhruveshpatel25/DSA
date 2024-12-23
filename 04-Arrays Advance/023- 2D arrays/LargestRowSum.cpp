/*1 2 3
  4 5 6
  7 8 9*/
#include<iostream>
#include<climits>
using namespace std;

int RowSum(int arr[][3],int size1, int size2){
    int maxi=INT_MIN;
    int index=0;

    //iterate the index column-wise
    for(int i=0; i<size1;i++){
        int sum=0;

        //iterate the complete row
        for(int j=0;j<size2;j++){
            sum=sum+arr[i][j];
        }

        //check if the current sum maximum
        if(sum>maxi){
            maxi=sum;

            //save the row number
            index=i;
        }     
    }
    return index;
}

int main(){
    int arr[3][3]={1,2,3,4,5,6,7,8,9};
    cout<<RowSum(arr,3,3);
}