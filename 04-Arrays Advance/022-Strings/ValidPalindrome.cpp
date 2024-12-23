#include<iostream>
#include<vector>
using namespace std;

bool Valid(char ch){

    //if is in between lower case alphabet or upper case alphabet or between digits
    if((ch>='a' && ch <='z') || (ch>='A' && ch <='Z') || (ch>='0' && ch <='9')){
        return true;
    }
    return false;
}

//convert to lowercase
char toLowercase(char ch){

    //if already in lowercase
    if(ch>='a'&&ch<='z'){
        return ch;
    }
    //if uppercase then convert to lowercase
    else{
        char temp=ch-'A'+'a';
        return temp;
    }
}

bool Palindrome(vector<string>& str){

    //temporary string
    string temp="";

    //iterate the complete string
    for(int i=0;i<str.size();i++){

        //for every element
        for(char ch: str[i]){
            //push the valid alphabet from string to temporary string
            if(Valid(ch)){
                temp.push_back(ch);
            }
        }
    }

    //start pointer
    int start=0;

    //end pointer
    int end=temp.size()-1;

    //iterate till they cross each other
    while(start<=end){

        //check if they are palindrome or not
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

