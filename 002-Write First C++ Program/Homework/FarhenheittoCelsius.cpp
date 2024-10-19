#include<iostream>
using namespace std;

int main(){
    float farhenheit;
    cout<<"Enter the temperature in farhenheit"<<endl;
    cin>>farhenheit;
    float celsius;
    celsius = ((farhenheit-32)*(5.0/9.0));
    cout<<"The temperatue in celsius is: "<<celsius<<endl;
}