#include<iostream>
using namespace std;

int counting(int num){
    if(num==0){
        return 1;
    }
    cout<<num<<endl;
    counting(num-1);  
}

int main(){
    int num;
    cout<<"Enter the number: ";
    cin>>num;
    counting(num);
}