#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int number;
    cout<<"Enter the value: ";
    cin>>number;
    bool flag=false;
    for(int i=0; i<=30;i++){
        int answer= pow(2,i);
        if(answer==number){
            cout<<"Is a Power of 2";
            flag=true;
        }
    }
    if(flag==false){
        cout<<"Not Power of 2";
    }
}
