#include<iostream>
using namespace std;

int factorial(int n){
    int fact=1;
    for(int i=1; i<=n; i++){
        fact=fact*i;
    }
    return fact;
}

int nCr(int n,int r){

    //formula=(n!/(n-r)!(r)!) 
    int numerator= factorial(n);
    int denominator= factorial(r)*factorial(n-r);
    return numerator/denominator;
}
int main(){
    int n,r;
    cout<<"Enter the value of n: ";
    cin>>n;
    cout<<"Enter the value of r: ";
    cin>>r;
    int answer;
    answer=nCr(n,r);
    cout<<"The answer is"<<answer<<endl;
}