#include<iostream>
using namespace std;

bool checkpalindrome(string& str,int start,int end){
    if(start>end){
        return true;
    }
    if(str[start]!=str[end]){
        return false;
    }else{
        start++;
        end--;
        return checkpalindrome(str,start,end);
    }
}

int main(){
    string str="abcba";
    bool result=checkpalindrome(str,0,str.length()-1);
    if(result){
        cout<<"The string is palindrome";
    }else{
        cout<<"The string is not palindrome";
    }
}