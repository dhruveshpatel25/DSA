#include<iostream>
using namespace std;

void print(int arr[], int size, int start=0){  //if start is not defined in main
    for(int i=start;i<size;i++){
        cout<<arr[i]<<endl;
    }
}

int main(){
    int arr[5]={1,2,3,4,5};
    cout<<"When start is not mentioned in main"<<endl;
    print(arr,5);
    cout<<"When start in mentioned"<<endl;
    print(arr,5,1);
}