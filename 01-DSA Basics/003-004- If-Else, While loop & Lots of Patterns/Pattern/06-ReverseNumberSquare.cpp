/*
25 24 23 22 21
20 19 18 17 16
15 14 13 12 11
10 9 8 7 6
5 4 3 2 1
*/
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