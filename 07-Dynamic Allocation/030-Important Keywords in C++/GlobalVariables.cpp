#include<iostream>
using namespace std;

//global variable-- bad pratice as it can be changed easily
int score=15;   

void a(int& i){

    //return score(15)
    cout<<score<<" in a"<<endl;

    //noe score 16
    score++;

    //local variable
    char ch='a';  
    cout<<ch<<endl;
}

void b(int& b){

    //will return score(16)(incremented because of void a)
    cout<<score<<" in b"<<endl;
}

int main(){

    //return score(15)
    cout<<score<<" in main"<<endl;
    int  i;
    a(i);
    b(i);
}