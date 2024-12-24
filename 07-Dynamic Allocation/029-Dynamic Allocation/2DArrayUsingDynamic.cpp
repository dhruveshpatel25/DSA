#include<iostream>
using namespace std;

int main(){
    int rows;
    cout<<"Enter the no. of rows: ";
    cin>>rows;

    int cols;
    cout<<"Enter the no. of cols: ";
    cin>>cols;

    //creating indivial array(row-wise)
    int **arr = new int*[rows]; 

    //creating columns in rows
    for(int i=0; i<rows; i++){ 
        arr[i] = new int[cols];
    }

    //entering the value in 2D Array
    for(int i=0; i<rows; i++){ 
        for(int j=0;j<cols;j++){
            cin>>arr[i][j];
        }
    }

    //displaying the value of 2D Array
    for(int i=0;i<rows;i++){  
        for(int j=0;j<cols;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    //first deleting the 2D Array formed in heap
    for(int i=0;i<rows;i++){ 
        delete[]arr[i];
    }

    //now deleting the pointer in stack
    delete []arr;  
}