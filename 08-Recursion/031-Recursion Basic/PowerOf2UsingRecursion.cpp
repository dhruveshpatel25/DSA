#include<iostream>
using namespace std;

int power(int num){

    //base case
    if(num==0){
        return 1;
    }

    //recursivly call for 2*2*2....(n times)
    return 2*power(num-1);
}

int main(){
    int num;
    cout<<"Enter the number: ";
    cin>>num;
    int result=power(num);
    cout<<result;
    return 0;
}