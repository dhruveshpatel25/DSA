#include<iostream>
using namespace std;

void Counting(int n){
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