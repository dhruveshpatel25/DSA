/*Reverse Words
Given a string s, reverse the string without reversing its individual words. Words are separated by spaces.
Note: The string may contain leading or trailing spaces, or multiple spaces between two words. The returned string should only have a single space separating the words, and no extra spaces should be included.

Examples :
Input: s = " i like this program very much "
Output: "much very program this like i"
Explanation: After removing extra spaces and reversing the whole string (not individual words), the input string becomes "much very program this like i". 

Input: s = " pqr mno "
Output: "mno pqr"
Explanation: After removing extra spaces and reversing the whole string, the input string becomes "mno pqr". 

Input: s = " a "
Output: "a"
Explanation: The input string contains only one word with extra spaces around it. After removing the extra spaces, the output is "a".
https://www.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1*/
#include<bits/stdc++.h>
using namespace std;

string reverseWords(string &s) {
    string ans="";
    string temp="";

    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] != ' ') {
            temp = s[i] + temp;  // Build the current word
        } else if (!temp.empty()) {
            // Add the word to the result
            if (!ans.empty()) ans += " ";
            ans += temp;
            temp = "";
        }
    }

    if (!temp.empty()) {
        if (!ans.empty()) ans += " ";
        ans += temp;
    }
    return ans;
}

int main() {
    string s = "  i   like   this   program very much  ";
    cout << "Input: \"" << s << "\"" << endl;
    string result = reverseWords(s);
    cout << "Output: \"" << result << "\"" << endl;

    return 0;
}