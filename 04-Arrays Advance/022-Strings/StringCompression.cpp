/*String Compression
Given an array of characters chars, compress it using the following algorithm:
Begin with an empty string s. For each group of consecutive repeating characters in chars:
If the group's length is 1, append the character to s.
Otherwise, append the character followed by the group's length.
The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.
After you are done modifying the input array, return the new length of the array.
You must write an algorithm that uses only constant extra space.

Example 1:
Input: chars = ["a","a","b","b","c","c","c"]
Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".

Example 2:
Input: chars = ["a"]
Output: Return 1, and the first character of the input array should be: ["a"]
Explanation: The only group is "a", which remains uncompressed since it's a single character.

Example 3:
Input: chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
Output: Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].
Explanation: The groups are "a" and "bbbbbbbbbbbb". This compresses to "ab12".
https://leetcode.com/problems/string-compression/description/*/
#include<iostream>
#include<vector>
using namespace std;

int StringCompression(vector<char>& char1){

    //pointer
    int i=0;

    //answer pointer
    int index=0;

    //size of array
    int n=char1.size();

    //iterate to end of array
    while(i<n){

        //next element
        int j=i+1;

        //check if the next element is same or not and the next element is within the range
        while(char1[i]==char1[j] && j<n){

            //if same move the pointer ahead
            j++;
        }

        //store the element at that answer index 
        char1[index++]=char1[i];

        //calculate the count of that element
        int count=j-i;

        //when the count for particular element is greater than 1
        if(count>1){

            //convert the count from 'int' to 'string'
            string number = to_string(count);
            for(char ch: number){

                //enter the count of that element next to element
                char1[index++]=ch;
            }
        }

        //move to next element
        i=j;
    }

    //return the size of the modified array
    return index;
}

int main(){
    vector<char> char1;
    char1.push_back('a');
    char1.push_back('a');
    char1.push_back('b');
    char1.push_back('b');
    char1.push_back('c');
    char1.push_back('c');
    char1.push_back('c');

    cout<<StringCompression(char1);
}