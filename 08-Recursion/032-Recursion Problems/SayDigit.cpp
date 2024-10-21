#include<iostream>
using namespace std;

void saydigit(int num, string arr[]){
    if(num==0){
        return;
    }
    int digit=num%10;
    num=num/10;
    saydigit(num,arr);
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