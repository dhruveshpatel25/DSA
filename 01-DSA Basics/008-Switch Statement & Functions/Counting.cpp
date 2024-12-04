#include<iostream>
using namespace std;

void Counting(int n){

    //count from 1 to n
    for(int i=1; i<=n; i++){
        cout<<i<<endl;
    }
}

int main(){
    int number;
    cout<<"Enter the number ";
    cin>>number;
    Counting(number);
}