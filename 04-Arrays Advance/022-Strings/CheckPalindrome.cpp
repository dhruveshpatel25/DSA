#include<iostream>
#include<vector>
using namespace std;

char toLowercase(char ch){
    if(ch>='a'&&ch<='z'){
        return ch;
    }else{
        char temp=ch-'A'+'a';
        return temp;
    }
}

bool Palindrome(vector<char>& arr){
    int start=0;
    int end=arr.size()-1;
    while(start<=end){
        if(toLowercase(arr[start++])==toLowercase(arr[end--])){
            return true;
        }else{
            return false;
        }
    }
    
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