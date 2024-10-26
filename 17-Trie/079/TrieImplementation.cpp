#include<iostream>
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
    Trie(){
        root=new Trienode('\0');
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

    bool searchutil(Trienode* root, string word){
        if(word.length()==0){
            return root->isTerminal;
        }
        int index=word[0]-'a';
        Trienode* child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }else{
            return false;
        }
        return searchutil(child,word.substr(1));
    }

    bool search(string word){
        return searchutil(root,word);
    }

    
};

int main(){
    Trie *t=new Trie();
    t->insert("abcd");
    cout<<"Present or not "<<t->search("abcd");
    return 0;
}