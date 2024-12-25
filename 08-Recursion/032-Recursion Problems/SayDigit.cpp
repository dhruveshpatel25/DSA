#include<iostream>
using namespace std;

void saydigit(int num, string arr[]){

    //base case
    if(num==0){
        return;
    }

    //take the last digit of number
    int digit=num%10;

    //remove that digit
    num=num/10;

    //recursivly call till first digit
    saydigit(num,arr);

    //print(so putting this after recursive call will make the first digit go first)
    cout<<arr[digit]<<" ";
}

int main(){
    string arr[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    int num;
    cout<<"Enter the num: ";
    cin>>num;

    saydigit(num,arr);
    return 0;
}