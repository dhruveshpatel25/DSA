#include<iostream>
using namespace std;

int score=15;  //global variable-- bad pratice as it can be changed easily 

void a(int& i){
    cout<<score<<" in a"<<endl;
    score++;
    char ch='a';  //local variable
    cout<<ch<<endl;
}

void b(int& b){
    cout<<score<<" in b"<<endl;
}

int main(){
    cout<<score<<" in main"<<endl;
    int  i;
    a(i);
    b(i);
}