#include<iostream>
#include<vector>
using namespace std;

bool Valid(char ch){
    if((ch>='a' && ch <='z') || (ch>='A' && ch <='Z') || (ch>='0' && ch <='9')){
        return true;
    }
    return false;
}

char toLowercase(char ch){
    if(ch>='a'&&ch<='z'){
        return ch;
    }else{
        char temp=ch-'A'+'a';
        return temp;
    }
}

bool Palindrome(vector<string>& str){
    string temp="";
    for(int i=0;i<str.size();i++){
        for(char ch: str[i])
        if(Valid(ch)){
            temp.push_back(ch);
        }
    }
    int start=0;
    int end=temp.size()-1;
    while(start<=end){
        if(toLowercase(temp[start++])!=toLowercase(temp[end--])){
            return false;
        }
    }
    return true;
}

int main(){
    vector<string> str;
    str.push_back("Nan");
    cout<<Palindrome(str);
}

