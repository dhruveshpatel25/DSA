#include<iostream>
using namespace std;

int main(){
    int product=1;
    int sum=0;
    int number;
    cout<<"Enter the number ";
    cin>>number;
    while(number!=0){
        int remainder= number%10;
        product=product*remainder;
        sum=sum+remainder;
        number=number/10;
    }
    int answer;
    answer= product-sum;
    cout<<answer;
}