/*
1
1 2
1 2 3
1 2 3 4
1 2 3 4 5
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
            cout<<" "<<j+1;
            j++;
        }
        cout<<endl;
        i++;
    }
}