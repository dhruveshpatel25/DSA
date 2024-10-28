#include<iostream>
using namespace std;
int main(){
    int num;
    cout<<"Enter the no. of loop: "<<endl;
    cin>>num;
    int sum=0;
    int i=1;
    while(i<=num){
        
        //check if the number is even or not
        if(i%2==0){
            sum=sum+i;
        }
        else{
            sum=sum;
        }
        i++;
    }
    cout<<"The sum of even numbers are: "<<sum<<endl;
}