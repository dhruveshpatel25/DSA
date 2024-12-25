#include<iostream>
using namespace std;

void walkingpath(int src, int dest){

    //base case-with sorce and destination are same
    if(src==dest){
        cout<<"Reached";
        return;
    }
    cout<<"The source is: "<<src<<endl;

    //move ahead
    src++;

    //recursivly check
    walkingpath(src,dest);
}

int main(){
    int dest;
    cout<<"Enter the destination: ";
    cin>>dest;

    int src;
    cout<<"Enter the source: ";
    cin>>src;

    walkingpath(src,dest);
}