/*Most Frequent Character
Given a string s of lowercase alphabets. The task is to find the maximum occurring character in the string s. If more than one character occurs the maximum number of times then print the lexicographically smaller character.
Examples:
Input: s = "testsample"
Output: 'e'
Explanation: e is the character which is having the highest frequency.

Input: s = "output"
Output: 't'
Explanation:  t and u are the characters with the same frequency, but t is lexicographically smaller.
https://www.geeksforgeeks.org/problems/maximum-occuring-character-1587115620/1*/
#include<iostream>
#include<vector>
using namespace std;

char Maximum(string s){

    //array to store all alphabet occurence
    int arr[26]={0};

    //iterate for the complete string
    for(int i=0;i<s.length();i++){
        char ch=s[i];
        int number=0;

        //if the string is in lowercase
        if(ch>='a'&&ch<='z'){

            //get the number of place of alphabet
            number=ch-'a';
        }

        //if string in uppercase
        else{

            //get the number of place of alphabet
            number=ch-'A';
        }

        //increase the count at that place
        arr[number]++;
    }

    //to store the maximum occurence of alphabet
    int maxi=-1;

    //to store the occuernce count
    int ans=0;

    //iterate the string completely
    for(int i=0;i<26;i++){
        if(arr[i]>maxi){
            ans=i;
            maxi=arr[i];
        }
    }

    //to get the actual alphabet
    char result='a'+ans;
    return result;
}

int main(){
    string s;
    cin>>s;
    cout<<Maximum(s);
}