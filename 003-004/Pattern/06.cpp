#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the no.of times "<<endl;
    cin>>n;
    int i=0;
    int count=1;
    while(i+1<=n){
        int j=0;
        while(j+1<=n){
            cout<<" "<<n*n-count+1;
            count++;
            j++;
        }
        cout<<endl;
        i++;
    }
}