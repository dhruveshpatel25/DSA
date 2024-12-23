#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

void Replace(string &s){

    //iterate the complete string
    for(int i=0; i<s.length();i++){

        //check for spaces
        if(s[i] ==' '){

            //if there exist space replace with '@40'
            s.replace(i,1,"@40");
        }
    }
}

int main(){
    string s;
    getline(cin,s);
    Replace(s);
    cout<<s;
}