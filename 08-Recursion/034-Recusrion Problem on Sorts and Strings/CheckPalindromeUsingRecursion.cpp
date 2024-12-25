/*Check If The String Is A Palindrome
You are given a string 'S'. Your task is to check whether the string is palindrome or not. For checking palindrome, consider alphabets and numbers only and ignore the symbols and whitespaces.
Note :
String 'S' is NOT case sensitive.

Example :
Let S = “c1 O$d@eeD o1c”.
If we ignore the special characters, whitespaces and convert all uppercase letters to lowercase, we get S = “c1odeedo1c”, which is a palindrome. Hence, the given string is also a palindrome.
https://www.naukri.com/code360/problems/check-if-the-string-is-a-palindrome_1062633*/
#include<iostream>
using namespace std;

bool checkpalindrome(string& str,int start,int end){

    //base case- when pointer cross each other meaning it is palindrome
    if(start>end){
        return true;
    }

    //if both are not same return false
    if(str[start]!=str[end]){
        return false;
    }
    
    //if both are same
    else{

        //move start pointer ahead
        start++;

        //move end pointer behind
        end--;

        //recursivly call for next element
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