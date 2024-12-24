#include<iostream>
using namespace std;

int getsum(int *arr, int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    return sum;
}

int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    int *arr=new int[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int result=getsum(arr,n);
    cout<<result;

    //infinite looping in static & dynamic memory allocation

    //static allocation - the variable lifespan will end with the bracket and the same space will be used stack
    while(true){  
        int i=5;
    }
    
    //dynamic allocation - the variable lifespan will end within the bracket but new space will be created for every loop in heap
    while(true){ 
        int *ptr = new int;
    }
}