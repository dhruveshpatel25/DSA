#include<iostream>
#include<vector>
using namespace std;

class Trienode{
    public:
    char data;
    Trienode* children[26];
    int childCount;
    bool isTerminal;

    Trienode(char ch){
        data=ch;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        childCount=0;
        isTerminal=false;
    }
};

class Trie{
    public:
    Trienode* root;
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
            root->childCount++;
            root->children[index]=child;
        }
        insertutil(child,word.substr(1));
    }
    void insert(string word){
        insertutil(root,word);
    }

    void lcp(string str,string &ans){
        for(int i=0;i<str.length();i++){
            char ch=str[i];
            if(root->childCount==1){
                ans.push_back(ch);
                int index=ch-'a';
                root=root->children[index];
            }else{
                break;
            }
            if(root->isTerminal){
                break;
            }
        }
    }

    string longestCommonPrefix(vector<string> arr,int n){
        Trie *t=new Trie('\0');
        for(int i=0;i<n;i++){
            t->insert(arr[i]);
        }
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
