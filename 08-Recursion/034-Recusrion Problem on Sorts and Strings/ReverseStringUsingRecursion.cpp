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
using namespace std;

void reversestring(string& str,int start,int end){

    //base case-if they both cross each other return the string
    if(start>end){
        return ;
    }

    //swap the elements
    swap(str[start],str[end]);

    //move the start pointer ahead
    start++;

    //move the end pointer behind
    end--;

    //recursivly call for next element
    return reversestring(str,start,end);
}

int main(){
    string str="abcde";
    reversestring(str,0,str.length()-1);
    cout<<str;
}