#include<iostream>
using namespace std;

int Fibonacci(int n){
    int a=0;
    int b=1;
    int c;
    for(int i=2; i<n;i++){
        int c=a+b;
        a=b;
        b=c;
    }
    return b;
    
}
int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    int answer=Fibonacci(n);
    cout<<answer;
}