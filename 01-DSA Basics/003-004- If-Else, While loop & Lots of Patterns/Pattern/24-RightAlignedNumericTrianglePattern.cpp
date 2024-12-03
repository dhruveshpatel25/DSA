/*
    1
   22
  333
 4444
55555
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
        while(j+1<=i+1){
            cout<<""<<i+1;
            j++;
        }
        cout<<endl;
        i++;
    }
}