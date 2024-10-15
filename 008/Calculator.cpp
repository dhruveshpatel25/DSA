#include<iostream>
using namespace std;

int main(){
    int number1,number2;
    char operation;
    cout<<"Enter First number ";
    cin>>number1;
    cout<<"Enter Second number ";
    cin>>number2;
    cout<<"Enter the operator ";
    cin>>operation;
    switch ( operation ) {
        case '+': cout<<(number1+number2)<<endl;
                  break;
        case '-':cout<<(number1-number2)<<endl;
                  break;
        case '*':cout<<(number1*number2)<<endl;
                  break;
        case '/':cout<<(number1/number2)<<endl;
                  break;
        case '%':cout<<(number1%number2)<<endl;
                  break;
        default: cout<<"Enter Valid Operator"<<endl;
    }
}