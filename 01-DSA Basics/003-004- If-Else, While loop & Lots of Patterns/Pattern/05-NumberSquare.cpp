/*
1 2 3 4 5
6 7 8 9 10
11 12 13 14 15
21 22 23 24 25
16 17 18 19 20
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
            cout<<" "<<count;
            count++;
            j++;
        }
        cout<<endl;
        i++;
    }    
}