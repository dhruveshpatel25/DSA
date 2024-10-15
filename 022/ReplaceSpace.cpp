#include<iostream>
#include<vector>
using namespace std;

void Replace(string &s){
    string temp=" ";
    for(int i=0;i<s.length();i++){
        if(s[i] == ' '){
            temp.push_back('@');
            temp.push_back('4');
            temp.push_back('0');
        }else{
            temp.push_back(s[i]);
        }
    }
    s=temp;
}

int main(){
    string s;
    getline(cin,s);
    Replace(s);
    cout<<s;
}