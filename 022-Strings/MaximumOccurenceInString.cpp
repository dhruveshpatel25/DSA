#include<iostream>
#include<vector>
using namespace std;

char Maximum(string s){
    int arr[26]={0};
    for(int i=0;i<s.length();i++){
        char ch=s[i];
        int number=0;
        if(ch>='a'&&ch<='z'){
            number=ch-'a';
        }else{
            number=ch-'A';
        }
        arr[number]++;
    }
    int maxi=-1;
    int ans=0;
    for(int i=0;i<26;i++){
        if(arr[i]>maxi){
            ans=i;
            maxi=arr[i];
        }
    }
    char result='a'+ans;
    return result;
}

int main(){
    string s;
    cin>>s;
    cout<<Maximum(s);
}