#include<iostream>
#include<vector>
using namespace std;

int StringCompression(vector<char>& char1){
    int i=0;
    int index=0;
    int n=char1.size();
    while(i<n){
        int j=i+1;
        while(char1[i]==char1[j] && j<n){
            j++;
        }
        char1[index++]=char1[i];
        int count=j-i;
        if(count>1){
            string number = to_string(count);
            for(char ch: number){
                char1[index++]=ch;
            }
        }
        i=j;
    }
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