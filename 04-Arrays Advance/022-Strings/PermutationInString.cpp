/*Permutation in String
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
In other words, return true if one of s1's permutations is the substring of s2.

Example 1:
Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:
Input: s1 = "ab", s2 = "eidboaoo"
Output: false
https://leetcode.com/problems/permutation-in-string/description/*/
#include<iostream>
#include<vector>
using namespace std;

bool Checkequal(int count1[26],int count2[26]){
    for(int i=0;i<26;i++){
        if(count1[i]!=count2[i]){
            return false;
        }
    }
    return true;
}

bool PermutationInString(string& chota, string& bada){
    int count1[26]={0};
    for(int i=0;i<chota.length();i++){
        int index=chota[i]-'a';
        count1[index]++;
    }

    int i=0;
    int windowsize=chota.length();
    int count2[26]={0};
    while(i<chota.length() && windowsize<=bada.length()){
        int index= bada[i]-'a';
        count2[index]++;
        i++;
    }
    if(Checkequal(count1,count2)){
        return 1;
    }   

    while(i<=bada.length()){
        char New=bada[i];
        int index= New-'a';
        count2[index]++;

        char Old=bada[i-windowsize];
        index= Old-'a';
        count2[index]--;

        i++;

        if(Checkequal(count1,count2)){
            return true;
        }
    }
}

int main(){
    string chota;
    cout<<"Enter the characters to be searched ";
    getline(cin,chota);
    string bada;
    cout<<"Enter the string to be checked ";
    getline(cin,bada);
    bool result=PermutationInString(chota,bada);
    if(result){
        cout<<"The character is present in string";
    }else{
        cout<<"The character is not present in string";
    }
}