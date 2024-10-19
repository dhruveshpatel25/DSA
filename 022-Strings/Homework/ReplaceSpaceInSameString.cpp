#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

void Replace(string &s){
    for(int i=0; i<s.length();i++){
        if(s[i] ==' '){
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