/*
ABCDE
ABCDE
ABCDE
ABCDE
ABCDE
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
        while(j+1<=n){
            cout<<(char)(65+j);
            j++;
        }
        cout<<endl;
        i++;
    }
}