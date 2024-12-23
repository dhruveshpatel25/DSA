/*Check If The String Is A Palindrome
You are given a string 'S'. Your task is to check whether the string is palindrome or not. For checking palindrome, consider alphabets and numbers only and ignore the symbols and whitespaces.
Note :
String 'S' is NOT case sensitive.

Example :
Let S = “c1 O$d@eeD o1c”.
If we ignore the special characters, whitespaces and convert all uppercase letters to lowercase, we get S = “c1odeedo1c”, which is a palindrome. Hence, the given string is also a palindrome.
https://www.naukri.com/code360/problems/check-if-the-string-is-a-palindrome_1062633*/
#include<iostream>
#include<vector>
using namespace std;

char toLowercase(char ch){

    //if elements are in lowercase
    if(ch>='a'&&ch<='z'){
        return ch;
    }
    
    //if elements are in uppercase
    else{
        char temp=ch-'A'+'a';
        return temp;
    }
}

bool Palindrome(vector<char>& arr){

    //left pointer
    int start=0;

    //right pointer
    int end=arr.size()-1;

    //iterate till they cross each other
    while(start<=end){

        //check if both left and right elements are same or not
        if(toLowercase(arr[start++])!=toLowercase(arr[end--])){
            return false;
        }
    }

    //if the string is palindrome
    return true;
    
}

int main(){
    vector<char> arr;
    arr.push_back('N');
    arr.push_back('a');
    arr.push_back('m');
    arr.push_back('a');
    arr.push_back('n');
    bool result = Palindrome(arr);
    if(result){
        cout<<"The string is Palindrome";
    }else{
        cout<<"The string is not Palindrome";
    }
}