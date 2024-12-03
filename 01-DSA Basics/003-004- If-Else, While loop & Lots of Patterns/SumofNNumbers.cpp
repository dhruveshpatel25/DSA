#include<iostream>
using namespace std;

int main(){
    int num;
    cout<<"Enter the number: "<<endl;
    cin>>num;
    int sum;
    sum=0;
    int i=1;

    //looping till i reaches the number
    while(i<=num){
        sum=sum+i;
        i=i+1;
    }
    cout<<"The Sum is:"<<sum<<endl;
}