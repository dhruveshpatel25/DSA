/*
       1
      2 3
     4 5 6
    7 8 9 10
  11 12 13 14 15
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
        int space=0;
         while(space<n-i+1){
            cout<<" ";
            space++;
        }
        while(j<=i){
            cout<<""<<count;
            count++;
            j++;
        }
        cout<<endl;
        i++;
    }
}