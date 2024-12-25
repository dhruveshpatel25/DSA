#include<iostream>
using namespace std;

bool linearsearch(int arr[],int size, int key){

    //base case
    if(size==0){
        return false;
    }

    //when element is found
    if(arr[0]==key){
        return true;
    }
    
    //when element not found
    else{

        //recursivly call for next element
        return linearsearch(arr+1,size-1,key);
    }
}

int main(){
    int arr[5]={1,2,3,4,5};
    int key=2;
    bool result=linearsearch(arr,5,key);
    if(result){
        cout<<"The element is found";
    }else{
        cout<<"The element is not found";
    }
}