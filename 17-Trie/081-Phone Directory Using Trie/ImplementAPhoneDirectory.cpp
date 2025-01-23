/* Implement a phone directory
You are given a list/array of strings which denotes the contacts that exist in your phone directory. The search query on a string ‘str’ which is a query string displays all the contacts which are present in the given directory with the prefix as ‘str’. One special property of the search function is that when a user searches for a contact from the contact list then suggestions (contacts with prefix as the string entered so for) are shown after the user enters each character.

Note :
If no suggestions are found, return an empty 2D array.
https://www.naukri.com/code360/problems/implement-a-phone-directory_1062666*/
#include<iostream>
#include<vector>
using namespace std;

class Trienode{
    public:

    //for storing the data
    char data;

    //for children node
    Trienode* children[26];

    //to check if it is last node or not
    bool isTerminal;

    Trienode(char ch){
        data=ch;
        for(int i=0;i<26;i++){

            // entering all the children valye as NULL
            children[i]=NULL;
        }

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

    void printSuggestion(Trienode* curr,vector<string> &temp,string prefix){

        //base case if reach the last alphabet
        if(curr->isTerminal){

            //all the value stored in prefix is stored in temp
            temp.push_back(prefix);
        }

        //iterate for all the child nodes
        for(char ch='a';ch <='z';ch++){
            Trienode* next=curr->children[ch-'a'];

            //if children
            if(next!=NULL){

                //pushback the child alphabet 
                prefix.push_back(ch);

                //recursivly iterate for the child node
                printSuggestion(next,temp,prefix);

                //after recursion pop out
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> getSuggestion(string str){

        //root node of that word
        Trienode* prev=root;

        //output to store the suggestions
        vector<vector<string>> output;

        //pointer storing the prefix of that iteration
        string prefix="";
        for(int i=0;i<str.length();i++){

            //push the alphabet to the predix string
            char lastch=str[i];
            prefix.push_back(lastch);

            //check if the root has a children for that input
            Trienode* curr=prev->children[lastch-'a'];

            //if the child node is NULL break out
            if(curr==NULL){
                break;
            }

            //if found print all the suggestion
            vector<string> temp;
            printSuggestion(curr,temp,prefix);

            //print all the temp to the output answer
            output.push_back(temp);

            //clear the temp vector
            temp.clear();

            //move the previous pointer to the current pointer
            prev=curr;
        }
        return output;
    }

    vector<vector<string>> phoneDirectory(vector<string>& contactList,string &queryStr){
        Trie *t=new Trie('\0');

        //insert all the contact in trie
        for(int i=0;i<contactList.size();i++){
            string str=contactList[i];
            t->insert(str);
            
        }
        
        return t->getSuggestion(queryStr);
    }
};

int main() {
    
    vector<string> contacts = {"John", "Jane", "Doe", "Smith", "David", "Daniel", "Alice"};
    string query = "Da";
    Trie phoneTrie('\0');
    
    vector<vector<string>> suggestions = phoneTrie.phoneDirectory(contacts, query);
    
    cout << "Suggestions for '" << query << "':" << endl;
    for (const auto& suggestionList : suggestions) {
        for (const auto& suggestion : suggestionList) {
            cout << suggestion << endl;
        }
    }

    return 0;
}