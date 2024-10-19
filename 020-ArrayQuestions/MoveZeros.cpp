#include<iostream>
#include<vector>
using namespace std;

void MoveZeros(vector<int>& arr){
    int i=0;
    for(int j=0;j<arr.size();j++){
        if(arr[j]!=0){
            swap(arr[j],arr[i]);
            i++;
        }
    }
}   

int main(){
    vector<int> arr;
    arr.push_back(0);
    arr.push_back(3);
    arr.push_back(0);
    arr.push_back(2);
    arr.push_back(0);
    arr.push_back(1);


    MoveZeros(arr);
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}   