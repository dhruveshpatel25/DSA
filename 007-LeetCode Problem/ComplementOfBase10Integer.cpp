#include<iostream>
using namespace std;

int main(){
    int number;
    cout<<"Enter the value: ";
    cin>>number;
    int m=number;
    int mask=0;
    int answer;
    while(m!=0){
        mask= (mask<<1)|1;
        m=m>>1;
    }
    while(number==0){
        return 1;
    }
    answer = ((~number) & mask );
    cout<<answer;
}