#include<iostream>
using namespace std;

int main(){
    int num;
    cout<<"Enter the number: "<<endl;
    cin>>num;
    int i=2;
    while(i<num){

        //if the remainder is 1 then not prime
        if(num%i==0){
            cout<<"The number is not Prime"<<endl;
        }
        else{
            cout<<"The number is Prime"<<endl;
        }
        i=i+1;
    }
}