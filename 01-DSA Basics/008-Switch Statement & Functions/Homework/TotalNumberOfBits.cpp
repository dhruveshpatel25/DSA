#include<iostream>
using namespace std;

int NumberOfSetBitsA(int n){
    int count=0;
    while(n!=0){

        if (n&1){
            count++;
        }
        n=n>>1;
    }
    return count;
}

int NumberOfSetBitsB(int n){
    int count=0;
    while(n!=0){
        if (n&1){
            count++;
        }
        n=n>>1;
    }
    return count;
}

int main(){
    int A,B;
    cout<<"Enter the value of A: ";
    cin>>A;
    cout<<"Enter the value of B: ";
    cin>>B;
    int answer1=NumberOfSetBitsA(A);
    int answer2=NumberOfSetBitsB(B);
    cout<<"The no. of set bits in A is: "<<answer1<<endl;
    cout<<"The no. of set bits in B is: "<<answer2<<endl;
    int total;
    total=answer1+answer2;
    cout<<"Total no.of set bits in A&B is "<<total<<endl;
}