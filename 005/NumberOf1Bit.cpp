#include<iostream>
using namespace std;

int main(){
    int number;
    cout<<"Enter the Binary number:";
    cin>> std::hex >> number;
    int count=0;
    while(number!=0){
        if(number & 1){
            count++;
        }

        number = number>>1;
        
    }
    cout << count;
    return 0;
}