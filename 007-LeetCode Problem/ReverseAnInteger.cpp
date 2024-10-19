#include<iostream>
#include<climits>
using namespace std;

int main(){
    int number;
    cout<<"Enter the number: ";
    cin>>number;
    int ans=0;
    while(number!=0){
        int remainder;
        remainder = number % 10;
        if(ans>INT_MAX/10 || ans<INT_MIN/10){
            return ans;
        }
        ans = (ans*10) + remainder;
        number=number/10;
    }
    cout<<"The reverse for the integer is: "<<ans<<endl;
}