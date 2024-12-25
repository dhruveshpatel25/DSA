#include<iostream>
using namespace std;

int counting(int num){

    //base case
    if(num==0){
        return 1;
    }
    cout<<num<<endl;

    //call for previous number(going descending order)
    counting(num-1);  
}

int main(){
    int num;
    cout<<"Enter the number: ";
    cin>>num;
    counting(num);
}