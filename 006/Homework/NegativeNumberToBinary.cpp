#include<iostream>
#include<math.h>
using namespace std;

int main(){

    int n;
    cout<<"Enter the negative no.: ";
    cin>>n;
    int numBits = sizeof(n)*8;
    unsigned int mask=1<<(numBits-1);
    for(int i=0;i<numBits;i++){
        cout<<  ((n & mask) ? '1':'0');
        mask>>=1;
    }
}