#include<iostream>
using namespace std;

int main(){
    int number;

    cout<<"Enter the value"<<endl;
    cin>>number;
    if(number>0){
        cout<<"The value is Positive"<<endl;
    }
    else if(number==0){
        cout<<"The value is Zero"<<endl;
    }
    else{
        cout<<"The value is Negative"<<endl;
    }
    return 0;
}