/*Replace Spaces
You have been given a string 'STR' of words. You need to replace all the spaces between words with “@40”.
https://www.naukri.com/code360/problems/replace-spaces_1172172*/
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