#include<iostream>
using namespace std;

int main(){
    int a = 4;
    int b = 5;

    cout<< "a&b: " << (a&b) << endl;
    cout<< "a|b: " << (a|b) <<endl;
    cout<< "~a: " << (~a) << endl;
    cout<< "a^b: " << (a^b) <<endl;

    // Right Shift and Left Shift

    cout<<"Right Shift Once "<<(a>>1)<<endl;
    cout<<"Right Shift Twice "<<(a>>2)<<endl;
    cout<<"Left Shift Once "<<(b<<1)<<endl;
    cout<<"Left Shift Twice "<<(b<<2)<<endl;

    // Pre/Post Increment/Decrement Operator

    cout<<"Pre-Increment "<<(++a)<<endl;
    cout<<"Post-Increment "<<(a++)<<endl;
    cout<<"Pre-Decrement "<<(--a)<<endl;
    cout<<"Post-Decrement "<<(a--)<<endl;
}