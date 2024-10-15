#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

string RemoveAllOccurrence(string& s, string& part){
    while(s.length()!=0 && s.find(part)<s.length()){
        s.erase(s.find(part),part.length());
    }
    return s;
}

int main(){
    string s;
    cout<<"Enter the string ";
    getline(cin,s);
    string part;
    cout<<"Enter the substring ";
    getline(cin,part);
    RemoveAllOccurrence(s,part);
    cout<<RemoveAllOccurrence(s,part);
}