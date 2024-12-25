/*Letter Combinations of a Phone Number
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. 
Return the answer in any order.
A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example 1:
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Example 2:
Input: digits = ""
Output: []

Example 3:
Input: digits = "2"
Output: ["a","b","c"]
https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/*/
#include<iostream>
#include<vector>
using namespace std;

void solve(string& str, int index, string& output, vector<string>& ans,string map[]){

    //base case
    if(index>=str.length()){
        ans.push_back(output);
        return;
    }

    //get the first element of string and convert it to numeric form
    int number = str[index]-'0';

    //find the alphabet aassociated with the number
    string value=map[number];

    //iterate the map
    for(int i=0;i<value.length();i++){

        //push the first element from map
        output.push_back(value[i]);

        //recursivly call for next element from the string and get possible output
        solve(str,index+1,output,ans,map);

        //backtracking by removing the current element
        output.pop_back();
    }
}

vector<string> keypad(string& str){

    //permanently store the answet
    vector<string> ans;
    if(str.length()==0){
        return ans;
    }

    //to store the temporary answer
    string output="";
    int index=0;

    //mapping to store the keypad
    string map[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    solve(str,index,output,ans,map);
    return ans;
}

int main() {
    string str;
    cin>>str;
    vector<string> result = keypad(str);
    cout<<"[";
    for (const auto& combination : result) {
        cout << combination <<" ";
    }
    cout<<"]";
}
