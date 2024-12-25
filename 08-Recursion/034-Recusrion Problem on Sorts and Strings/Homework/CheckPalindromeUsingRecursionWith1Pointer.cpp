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

bool checkpalindrome(string& str,int start){

    //base case-when start pointer crossed middle element
    if(start>str.length()-start-1){
        return true;
    }

    //when the elements are not same
    if(str[start]!=str[str.length()-start-1]){
        return false;
    }
    
    //if they are same check for other elements
    else{

        //move the pointer ahead
        start++;

        //recursivly call for next element
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