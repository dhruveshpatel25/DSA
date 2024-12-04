#include<iostream>
#include<math.h>
using namespace std;

int main(){

    int n;
    cout<<"Enter the no.: ";
    cin>>n;
    float ans = 0;
    int i = 0;

    while(n!=0){

        //take the last digit
        int digit = n%10;

        //if 1 found multiply by the 2th power
        if(digit == 1){
            ans=ans+(digit*pow(2,i));
        }

        //remove the last digit
        n= n/10;
        i++;
    }
    cout<<"The no. is: "<<ans<<endl;
}