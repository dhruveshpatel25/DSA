#include<iostream>
using namespace std;

bool Search(int arr[], int size, int key){
    for(int i=0; i<size; i++ ){

        //iterate till you get the key value
        if(arr[i]==key){
            return 1;
        }
    }
    return 0;
}

int main(){
    int arr[10]={0,1,2,3,4,5,6,7,8,9};
    int key;
    cout<<"Enter the key to be searched: ";
    cin>>key;
    bool found= Search(arr,10,key);
    if(found){
        cout<<"The key is present";
    }else{
        cout<<"The key is not present";
    }
}