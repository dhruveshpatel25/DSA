#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    int a= 0;
    int b= 1;
    cout<<a<<" "<<b<<" ";

    //Looping till the size reacched
    for(int i=0;i <= n;i++){
        int Nextnumber= a+b;
        cout<<Nextnumber<<" ";
        a=b;
        b=Nextnumber;
    }
}