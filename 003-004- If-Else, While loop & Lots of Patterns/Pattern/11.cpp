#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the no.of times "<<endl;
    cin>>n;
    int i=0;
    int count=0;
    while(i+1<=n){
        int j=0;
        int count=n-i;
        while(j+1<=i+1){
            cout<<""<<n-count+1;
            count++;
            j++;
        }
        cout<<endl;
        i++;
    }
}