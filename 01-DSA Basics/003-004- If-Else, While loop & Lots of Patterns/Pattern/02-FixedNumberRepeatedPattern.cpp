/*
11111
22222
33333
44444
55555
*/
#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the no. of times"<<endl;
    cin>>n;
    int i=0;
    while(i+1<=n){
        int j=0;
        while(j+1<=n){
            cout<<""<<i+1;
            j++;
        }
        cout<<endl;
        i++;
    }
}