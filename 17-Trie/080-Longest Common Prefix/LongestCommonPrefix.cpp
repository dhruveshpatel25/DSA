/*Longest Common Prefix
You are given an array ‘ARR’ consisting of ‘N’ strings. Your task is to find the longest common prefix among all these strings. If there is no common prefix, you have to return an empty string.

A prefix of a string can be defined as a substring obtained after removing some or all characters from the end of the string.

For Example:
Consider ARR = [“coding”, ”codezen”, ”codingninja”, ”coders”]
The longest common prefix among all the given strings is “cod” as it is present as a prefix in all strings. Hence, the answer is “cod”.
https://www.naukri.com/code360/problems/longest-common-prefix_2090383?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar*/
#include<iostream>
#include<vector>
using namespace std;

class Trienode{
    public:

    //for storing the data
    char data;

    //for children node
    Trienode* children[26];

    //to keep the count of child
    int childCount;

    //to check if it is last node or not
    bool isTerminal;

    Trienode(char ch){
        data=ch;
        for(int i=0;i<26;i++){

            // entering all the children valye as NULL
            children[i]=NULL;
        }

        //child is now considered 0 at start
        childCount=0;

        //terminal is flagged as false
        isTerminal=false;
    }
};

class Trie{
    public:
    Trienode* root;

    //the root node will always be '\0'
    Trie(char ch){
        root=new Trienode(ch);
    }
    /*string longestCommonPrefix(vector<string> &arr,int n){
        string ans="";
        for(int i=0;i<arr[0].length();i++){
            char ch=arr[0][i];
            bool match=true;
            for(int j=1;j<n;j++){
                if(arr[j].size()<i || ch!=arr[j][i]){
                    match=false;
                    break;
                }
            }
            if(match==false){
                break;
            }else{
                ans.push_back(ch);
            }
        }
        return ans;
    }*/

   //insert logic
    void insertutil(Trienode* root, string word){

        //base case to check length of word
        if(word.length()==0){

            //last character is terminal
            root->isTerminal=true;
            return;
        }

        //hashing the alphadet to the number
        int index=word[0]-'a';
        Trienode* child;

         //check if the node is present or not
        if(root->children[index]!=NULL){

            //move the child to that 'found child'
            child=root->children[index];
        }else{

            //create a new child node
            child= new Trienode(word[0]);

            //increase the count to keep track of child nodes
            root->childCount++;

            //make the child as children of the node
            root->children[index]=child;
        }

        //recursivly call the function by removing the first character of the string
        insertutil(child,word.substr(1));
    }
    //insert operation
    void insert(string word){
        insertutil(root,word);
    }

    void lcp(string str,string &ans){
        for(int i=0;i<str.length();i++){

            //iterate for each alphabet in trie
            char ch=str[i];

            //if the child count is 1
            if(root->childCount==1){

                //push the alphabet in ans array
                ans.push_back(ch);

                //hashing the character to find it in trie
                int index=ch-'a';

                //move to the child node to check for more 
                root=root->children[index];
            }else{

                //if the childcount is greater than 1 then break out of loop
                break;
            }

            //if the loop has reached the last word then break out
            if(root->isTerminal){
                break;
            }
        }
    }

    string longestCommonPrefix(vector<string> arr,int n){

        //start with '\0'
        Trie *t=new Trie('\0');

        //put all the answer in the trie
        for(int i=0;i<n;i++){
            t->insert(arr[i]);
        }

        //start with the first word
        string first=arr[0];
        string ans="";
        t->lcp(first,ans);
        return ans;
    }
};

int main() {
    vector<string> input = {"apple", "ape", "apricot", "application"};
    Trie trie('\0');

    for (const string& word : input) {
        trie.insert(word);
    }
    string commonPrefix = trie.longestCommonPrefix(input, input.size());
    if (commonPrefix.empty()) {
        cout << "No common prefix found." << endl;
    } else {
        cout << "Longest Common Prefix: " << commonPrefix << endl;
    }

    return 0;
}
