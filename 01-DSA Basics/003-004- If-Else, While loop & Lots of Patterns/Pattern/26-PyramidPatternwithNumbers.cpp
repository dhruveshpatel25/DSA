/*
      1
     121
    12321
   1234321
  123454321
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
        int space=0;
         while(space<n-i+1){
            cout<<" ";
            space++;
        }
        while(j<=i){
            cout<<""<<j+1;
            j++;
        }
        while(j>1){
            cout<<""<<j-1;
            j=j-1;
        }
        cout<<endl;
        i++;
    }
}