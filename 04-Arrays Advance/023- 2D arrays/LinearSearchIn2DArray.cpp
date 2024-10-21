#include<iostream>
using namespace std;

bool Search(int arr[][3], int size1,int size2, int key){
    for(int i=0; i<size1; i++ ){
        for(int j=0; j<size2;j++){
            if(arr[i][j]==key){
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    int arr[3][3]={1,2,3,4,5,6,7,8,9};
    int key;
    cout<<"Enter the key to be searched: ";
    cin>>key;
    bool found= Search(arr,3,3,key);
    if(found){
        cout<<"The key is present";
    }else{
        cout<<"The key is not present";
    }
}