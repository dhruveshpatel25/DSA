#include<iostream>
using namespace std;

int main(){
    int a = 4;
    int b = 5;

    cout<< "a&b: " << (a&b) << endl; //4(minimum value)
    cout<< "a|b: " << (a|b) <<endl;  //5(maximum value)
    cout<< "~a: " << (~a) << endl; //-5 (negative value)
    cout<< "a^b: " << (a^b) <<endl; //1 (to check if distinct no or not)

    // Right Shift and Left Shift

    cout<<"Right Shift Once "<<(a>>1)<<endl; //2(division by 2)
    cout<<"Right Shift Twice "<<(a>>2)<<endl; // 1 (division by 2^2)
    cout<<"Left Shift Once "<<(b<<1)<<endl; //10 (multiply by 2)
    cout<<"Left Shift Twice "<<(b<<2)<<endl; //20 (multipply by 2^2)

    // Pre/Post Increment/Decrement Operator

    cout<<"Pre-Increment "<<(++a)<<endl; //5(Increases first then print)
    cout<<"Post-Increment "<<(a++)<<endl; //5 (Print first then increase)
    cout<<"Pre-Decrement "<<(--a)<<endl; //5 (Decrease first then print)
    cout<<"Post-Decrement "<<(a--)<<endl; //5 (Print first then decrease)
}