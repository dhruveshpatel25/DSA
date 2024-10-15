#include<iostream>
using namespace std;

void walkingpath(int src, int dest){
    if(src==dest){
        cout<<"Reached";
        return;
    }
    cout<<"The source is: "<<src<<endl;
    src++;
    walkingpath(src,dest);
}

int main(){
    int dest;
    cout<<"Enter the destination ";
    cin>>dest;

    int src;
    cout<<"Enter the source: ";
    cin>>src;

    walkingpath(src,dest);
}