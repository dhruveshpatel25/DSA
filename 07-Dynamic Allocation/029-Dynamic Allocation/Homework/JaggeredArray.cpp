#include<iostream>
using namespace std;
//Jaggered Array is the type of array in which the no. of coulmns on each row is variable
int main(){
    int rows;
    cout<<"Enter the no. of rows: ";
    cin>>rows;

    int col;
    int *colarr=new int[rows];

    int **arr = new int*[rows];

    //iterate for all row index
    for(int i=0;i<rows;i++){
        cout<<"Enter the value of columns: ";
        cin>>colarr[i];

        //make an array for that particular row
        arr[i] = new int[colarr[i]];

        //now enter the element for particular row
        for(int j=0;j<colarr[i];j++){
            cin>>arr[i][j];
        }
    }

    //displaying the value of Jaggered Array
    for(int i=0;i<rows;i++){
        for(int j=0;j<colarr[i];j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    //first deleting the Jaggered Array formed in heap
    for(int i=0;i<rows;i++){
        delete[]arr[i];
    }

    //now deleting the pointer in stack
    delete []arr;
}