#include<iostream>
using namespace std;

int fibonacci(int place){
    if(place==0){
        return 0;
    }
    if(place==1){
        return 1;
    }
    int ans= fibonacci(place-1)+fibonacci(place-2);
    return ans;
}

int main(){
    int place;
    cout<<"Enter the position: ";
    cin>>place;
    int result=fibonacci(place);
    cout<<"The value is "<<result;
    return 0;
}