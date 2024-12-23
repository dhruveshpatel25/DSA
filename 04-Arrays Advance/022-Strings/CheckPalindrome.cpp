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