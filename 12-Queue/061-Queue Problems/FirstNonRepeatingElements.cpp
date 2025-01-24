/*Stream First Non-repeating
Given an input stream s consisting only of lowercase alphabets. While reading characters from the stream, you have to tell which character has appeared only once in the stream upto that point. If there are many characters that have appeared only once, you have to tell which one of them was the first one to appear. If there is no such character then append '#' to the answer.
NOTE:
1. You need to find the answer for every i (0 <= i < n)
2. In order to find the solution for every you need to consider the string from starting position till the ith position.
 
Examples:

Input: s = "aabc"
Output: "a#bb"
Explanation: For every ith character we will consider the string from index 0 till index i first non repeating character is as follow- "a" - first non-repeating character is 'a' "aa" - no non-repeating character so '#' "aab" - first non-repeating character is 'b' "aabc" - there are two non repeating characters 'b' and 'c',  first non-repeating character is 'b' because 'b' comes before 'c' in the stream.

Input: s = "zz"
Output: "z#"
Explanation: For every character first non repeating character is as follow- "z" - first non-repeating character is 'z' "zz" - no non-repeating character so '#' 

Input: s = "bb"
Output: "b#"
Explanation: For every character first non repeating character is as follow- "b" - first non-repeating character is 'b' "bb" - no non-repeating character so '#' 
https://www.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1*/
#include<iostream>
#include<queue>
#include<stack>
#include<map>
using namespace std;

string NonRepeating(string str){
    map<char,int> m;
    string ans="";
    queue<char> que;

    for(int i=0;i<str.length();i++){
        char ch=str[i];
        que.push(ch);

        //increase the counter
        m[ch]++;

        while(!que.empty()){

            //rif count greater than 1 remove the element
            if(m[que.front()]>1){
                que.pop();
            }else{

                //push the non-repeating elements
                ans.push_back(que.front());
                break;
            }
        }
        
        //pushing '#' for repeating elements
        if(que.empty()){
            ans.push_back('#');
        }
    }
    return ans;
}

int main() {
    string str = "aabbbccddee";
    string result = NonRepeating(str);
    cout << "Original string: " << str << endl;
    cout << "Non-repeating characters: " << result << endl;
    return 0;
}
