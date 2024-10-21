#include<iostream>
using namespace std;

void reversestring(string& str,int start,int end){
    if(start>end){
        return ;
    }
    swap(str[start],str[end]);
    start++;
    end--;
    return reversestring(str,start,end);
}

int main(){
    string str="abcde";
    reversestring(str,0,str.length()-1);
    cout<<str;
}