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

        //multiply the last bit with 1 if odd number 1 will be the answer and 0 if even
        int bit = n&1;

        //multiply by the power of 10 of that place
        ans = (bit * pow(10,i))+ans;

        //right shift by 1
        n = n >> 1;
        i++;
    }
    cout<<"The answer is: "<<ans<<endl;
}