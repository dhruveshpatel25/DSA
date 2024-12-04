#include<iostream>
using namespace std;

int Addition(int num[], int n){
    int sum=0;

    //loop to add the number to get the sum
    for(int i=0; i<n; i++){
        sum= sum+num[i];
    }
    return sum;
}

int main(){
    int size;
    cout<<"Enter the value of size:";
    cin>>size;

    int num[1000];
    for(int i=0; i<size; i++){
        cin>>num[i];
    }
    cout<<"The sum of all values in array are: "<<Addition(num,size);
}