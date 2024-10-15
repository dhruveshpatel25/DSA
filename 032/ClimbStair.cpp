#include<iostream>
using namespace std;

int climbstair(int num){
    if(num<0){
        return 0;
    }
    if(num==0){
        return 1;
    }

    return climbstair(num-1)+climbstair(num-2);
}

int main(){
    int num;
    cout<<"Enter the no.of stairs: ";
    cin>>num;
    int result=climbstair(num);
    cout<<"No. of ways are: "<<result;
}