#include<iostream>
using namespace std;

bool checkpalindrome(string& str,int start){
    if(start>str.length()-start-1){
        return true;
    }
    if(str[start]!=str[str.length()-start-1]){
        return false;
    }else{
        start++;
        return checkpalindrome(str,start);
    }
}

int main(){
    string str="abcba";
    bool result=checkpalindrome(str,0);
    if(result){
        cout<<"The string is palindrome";
    }else{
        cout<<"The string is not palindrome";
    }
}