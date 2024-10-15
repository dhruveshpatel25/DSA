#include<iostream>
#include<vector>
using namespace std;

string RemoveDuplicates( string& s){
    int i=0;
    while(i<s.length()){
        if(s[i]==s[i+1]){
            s.erase(i,2);
            i=0;
        }else{
            i++;
        }
    }
    return s;
}

int main(){ 
    string s;
    cout<<"Enter the string: ";
    getline(cin,s);
    cout<<RemoveDuplicates(s);
}