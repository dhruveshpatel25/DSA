#include<iostream>
using namespace std;

int power(int num,int pow){
    if(pow==0){
        return 1;
    }
    return num*power(num,pow-1);
}

int main(){
    int num;
    cout<<"Enter the number: ";
    cin>>num;

    int pow;
    cout<<"Enter the power: ";
    cin>>pow;

    int result=power(num,pow);
    cout<<result;
    return 0;
}