/*Remove All Adjacent Duplicates In String
You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.
We repeatedly make duplicate removals on s until we no longer can.
Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.
Example 1:
Input: s = "abbaca"
Output: "ca"
Explanation: 
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".

Example 2:
Input: s = "azxxzy"
Output: "ay"*/
#include<iostream>
#include<vector>
using namespace std;

string RemoveDuplicates( string& s){

    //pointer
    int i=0;
    while(i<s.length()){

        //check the particular element and its next element
        if(s[i]==s[i+1]){

            //if same remove of length 2
            s.erase(i,2);

            //revert the pointer back to start
            i=0;
        }
        
        //if the elements are not same
        else{

            //move the pointer ahead
            i++;
        }
    }
    return s;
}

int main(){ 
    string s;
    cout<<"Enter the string: ";
    getline(cin,s);
    cout<<RemoveDuplicates(s);
}