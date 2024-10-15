#include<iostream>
using namespace std;

void reversestring(string& str,int start){
    if(start>str.length()-start-1){
        return ;
    }
    swap(str[start],str[str.length()-start-1]);
    start++;
    return reversestring(str,start);
}

int main(){
    string str="abcde";
    reversestring(str,0);
    cout<<str;
}