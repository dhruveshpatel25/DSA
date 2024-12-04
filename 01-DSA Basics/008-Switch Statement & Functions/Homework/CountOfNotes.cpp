#include<iostream>
using namespace std;

int main(){
    int amount;
    cout<<"Enter the amount: ";
    cin>>amount;
    int remaining=amount;

    //if amount greater than 100
    switch(remaining/100){
        case 0: cout<<"No 100rs. note"<<endl;
                break;
        default: cout<<"No. of 100rs note are "<<remaining/100<<endl;
                remaining= remaining%100;
    }

    //if amount greater than 50
    switch(remaining/50){
        case 0: cout<<"No 50rs. note"<<endl;
                break;
        default: cout<<"No. of 50rs note are "<<remaining/50<<endl;
                  remaining= remaining%50;
    }

    //if amount greater than 20
    switch(remaining/20){
        case 0: cout<<"No 20rs. note"<<endl;
                break;
        default: cout<<"No. of 20rs note are "<<remaining/20<<endl;
                  remaining= remaining%20;
    }

    //if amount greater than 10
    switch(remaining/10){
        case 0: cout<<"No 10rs. note"<<endl;
                break;
        default: cout<<"No. of 10rs note are "<<remaining/10<<endl;
                 remaining= remaining%10;
    }

    //if amount greater than 5
    switch(remaining/5){
        case 0: cout<<"No 5rs. note"<<endl;
                break;
        default: cout<<"No. of 5rs note are "<<remaining/5<<endl;;
                  remaining= remaining%5;
    }

    //if amount greater than 1
    switch(remaining/1){
        case 0: cout<<"No 1rs. note"<<endl;
                break;
        default: cout<<"No. of 1rs note are "<<remaining/1<<endl;
                 remaining= remaining%1;
    }
}