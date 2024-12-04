#include<iostream>
using namespace std;

bool IsPrime(int n){
    for(int i=2; i<=n;i++){

        //if divisble return 0 as false
        if(n%i==0){
            return 0;
        }
    }

    //if not return 1 as true
    return 1;
}
int main(){
    int number;
    cout<<"Enter the number ";
    cin>>number;
    //IsPrime(number);
    if(IsPrime(number)){
        cout<<"It is Prime number";                                 
    }else{
        cout<<"It is not Prime number";
    }
}