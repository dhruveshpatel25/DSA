#include<iostream>
#include<vector>
using namespace std;

class Trienode{
    public:
    char data;
    Trienode* children[26];
    bool isTerminal;

    Trienode(char ch){
        data=ch;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal=false;
    }
};

class Trie{
    public:
    Trienode* root;
    Trie(char ch){
        root=new Trienode(ch);
    }
    void insertutil(Trienode* root, string word){
        if(word.length()==0){
            root->isTerminal=true;
            return;
        }
        int index=word[0]-'a';
        Trienode* child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }else{
            child= new Trienode(word[0]);
            root->children[index]=child;
        }
        insertutil(child,word.substr(1));
    }
    void insert(string word){
        insertutil(root,word);
        
    }

    void printSuggestion(Trienode* curr,vector<string> &temp,string prefix){
        if(curr->isTerminal){
            temp.push_back(prefix);
        }
        for(char ch='a';ch <='z';ch++){
            Trienode* next=curr->children[ch-'a'];
            if(next!=NULL){
                prefix.push_back(ch);
                printSuggestion(next,temp,prefix);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> getSuggestion(string str){
        Trienode* prev=root;
        vector<vector<string>> output;
        string prefix="";
        for(int i=0;i<str.length();i++){
            char lastch=str[i];
            prefix.push_back(lastch);
            Trienode* curr=prev->children[lastch-'a'];
            if(curr==NULL){
                break;
            }
            vector<string> temp;
            printSuggestion(curr,temp,prefix);
            output.push_back(temp);
            temp.clear();
            prev=curr;
        }
        return output;
    }

    vector<vector<string>> phoneDirectory(vector<string>& contactList,string &queryStr){
        Trie *t=new Trie('\0');
        
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