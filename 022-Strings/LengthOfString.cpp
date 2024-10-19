#include<iostream>
#include<vector>
using namespace std;

int Length(vector<char>& arr){
    int count=0;
    for(int i=0; arr[i]!='\0';i++){
        count++;
    }
    return count;
}

int main(){
    vector<char> arr;
    arr.push_back('D');
    arr.push_back('h');
    arr.push_back('r');
    arr.push_back('u');
    arr.push_back('v');
    arr.push_back('e');
    arr.push_back('s');
    arr.push_back('h');
    int result=Length(arr);
    cout<<result;
}