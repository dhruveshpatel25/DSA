#include<iostream>
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
    Trie(){
        root=new Trienode('\0');
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

    //search logic
    bool searchutil(Trienode* root, string word){

        //base case
        if(word.length()==0){

            //return the terminal flag whether it is present or not
            return root->isTerminal;
        }

        //hashing the alphadet to the number
        int index=word[0]-'a';
        Trienode* child;

        //check if the roots child is present or not
        if(root->children[index]!=NULL){

            //move to the child node
            child=root->children[index];
        }else{

            //if not present then return false
            return false;
        }
        return searchutil(child,word.substr(1));
    }

    //search operation
    bool search(string word){
        return searchutil(root,word);
    }
    
    bool removeutil(Trienode* root,string word){

        //base case
        if(word.length()==0){

            //check if the word exist
            if(root->isTerminal==true){

                // if it exist convert the terminal flag to false
                root->isTerminal=false;

                //loop for all the children of that node
                for(int i=0;i<26;i++){

                    //check if it has any children
                    if(root->children[i]!=NULL){

                        //if it has children return false to not delete the node it
                        return false;
                    }
                }

                //if the node has no child node then return true to delete the node
                return true;
            }

            //if the word does not exist in the trie
            return false;
        }

        //hashing the alphadet to the number
        int index = word[0]-'a';

        //making the child pointer to the child of the node
        Trienode* child=root->children[index];

        //check if child is present or not
        if(root->children[index]==NULL){

            //return false if the child is not present
            return false;
        }

        //recursivly iterate to check for all the alphabet of the word to check can we delete the node or not
        bool shouldDelete=removeutil(child,word.substr(1));

        //based on the output
        if(shouldDelete){

            //if the condition is true than delete the node
            delete child;

            //make that child as NULL in the parent(root) node
            root->children[index]=NULL;

            //now iterate for all the child in that parent node
            for(int i=0;i<26;i++){

                //check if there exist any children node
                if(root->children[i]!=NULL){

                    //if there exist then return false to not delete it
                    return false;
                }
            }

            //if isterminal flag is true(meaning it is terminal alphabet of another word so return false to not delete it)
            //if isterminal flag is false(meaning it is not terminal alphabet so delete it)
            return !root->isTerminal;
        }

        //means that do not delete the node if it is not safe to delete
        return false;
    }

    void remove(string word){
        removeutil(root,word);
    }
};

int main(){
    Trie *t=new Trie();
    t->insert("abc");
    t->insert("abcd");
    cout<<"Present or not "<<t->search("abc");
    t->remove("abc");
    cout<<"Present or not "<<t->search("abc");
    return 0;
}