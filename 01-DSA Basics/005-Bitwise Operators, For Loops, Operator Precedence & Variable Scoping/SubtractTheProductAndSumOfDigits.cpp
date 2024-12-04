#include<iostream>
using namespace std;

int main(){
    int product=1;
    int sum=0;
    int number;
    cout<<"Enter the number ";
    cin>>number;
    while(number!=0){

        //last digit of the number
        int remainder= number%10;

        //multiply the previous product
        product=product*remainder;

        //add the previous sum
        sum=sum+remainder;

        //remove the last digit
        number=number/10;
    }
    int answer;

    //calculate the answer
    answer= product-sum;
    cout<<answer;
}