#include<iostream>
using namespace std;

int AP(int n){

    //AP formula
    int ap= 3*n+7;
    return ap;
}

int main(){
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;

    int answer;
    answer=AP(n);
    cout<<"The AP is: "<<answer;
}