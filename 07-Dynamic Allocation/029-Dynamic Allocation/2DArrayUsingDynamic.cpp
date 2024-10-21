#include<iostream>
using namespace std;

int main(){
    int rows;
    cout<<"Enter the no. of rows: ";
    cin>>rows;

    int cols;
    cout<<"Enter the no. of cols: ";
    cin>>cols;

    int **arr = new int*[rows]; //creating indivial array(row-wise)

    for(int i=0; i<rows; i++){ //creating columns in rows
        arr[i] = new int[cols];
    }

    for(int i=0; i<rows; i++){ //entering the value in 2D Array
        for(int j=0;j<cols;j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0;i<rows;i++){  //displaying the value of 2D Array
        for(int j=0;j<cols;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i=0;i<rows;i++){ // first deleting the 2D Array formed in heap
        delete[]arr[i];
    }

    delete []arr;  //now deleting the pointer in stack
}