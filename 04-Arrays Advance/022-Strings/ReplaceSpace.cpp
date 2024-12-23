#include<iostream>
#include<vector>
using namespace std;

void Replace(string &s){

    //temporary string
    string temp=" ";

    //iterate for complete string
    for(int i=0;i<s.length();i++){

        //if there exist a space
        if(s[i] == ' '){

            //pusg '@40'
            temp.push_back('@');
            temp.push_back('4');
            temp.push_back('0');
        }
        
        //if there is no space
        else{
            temp.push_back(s[i]);
        }
    }

    //copy the temporary string in s
    s=temp;
}

int main(){
    string s;
    getline(cin,s);
    Replace(s);
    cout<<s;
}