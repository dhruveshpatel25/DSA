#include<iostream>
using namespace std;

//if-else function in form of inline
inline int getmax(int& a,int& b){
    return (a>b) ? a:b;  
}

int main(){
    int a=1;
    int b=2;

    int ans=0;

    ans=getmax(a,b);
    cout<<ans<<endl;
}