/*
 1
 2 3
 3 4 5
 4 5 6 7
 5 6 7 8 9
*/
#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the no.of times "<<endl;
    cin>>n;
    int i=0;
    while(i+1<=n){
        int j=0;
        while(j+1<=i+1){
            cout<<" "<<i+j+1;
            j++;
        }
        cout<<endl;
        i++;
    }
}