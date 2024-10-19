#include<iostream>
#include<vector>
using namespace std;

void Reverse(vector<char>& arr){
    int start=0;
    int end=arr.size()-1;
    while(start<=end){
        swap(arr[start++],arr[end--]);
    }
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
    Reverse(arr);
    for(int k=0;k<arr.size();k++){
        cout<<arr[k]<<" ";
    }
}