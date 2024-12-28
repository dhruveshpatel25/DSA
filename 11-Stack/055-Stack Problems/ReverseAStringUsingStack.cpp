/*Reverse String
Write a function that reverses a string. The input string is given as an array of characters s.
You must do this by modifying the input array in-place with O(1) extra memory.
Example 1:
Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]

Example 2:
Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
https://leetcode.com/problems/reverse-string/description/*/
#include<iostream>
#include<stack>
using namespace std;

int main(){
    string str="dhruvesh";
    stack<char> s;
    for(int i=0;i<str.length();i++){

        //take the element
        char ch=str[i];

        //push in stack
        s.push(ch);
    }

    string ans="";
    while(!s.empty()){

        //take the top element
        char ch=s.top();

        //add in stack
        ans.push_back(ch);

        //remove the top element
        s.pop();
    }
    cout<<ans;
}