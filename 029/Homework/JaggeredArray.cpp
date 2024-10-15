#include<iostream>
using namespace std;

int main(){
    int rows;
    cout<<"Enter the no. of rows: ";
    cin>>rows;

    int col;
    int *colarr=new int[rows];

    int **arr = new int*[rows];

    for(int i=0;i<rows;i++){
        cout<<"Enter the value of columns: ";
        cin>>colarr[i];
        arr[i] = new int[colarr[i]];
        for(int j=0;j<colarr[i];j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<rows;i++){
        for(int j=0;j<colarr[i];j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i=0;i<rows;i++){
        delete[]arr[i];
    }

    delete []arr;
    
}