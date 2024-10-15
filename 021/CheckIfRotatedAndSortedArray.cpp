#include<iostream>
#include<vector>
using namespace std;

bool Check(vector<int>& arr){
    int count=0;
    int n=arr.size()-1;
    for(int i=1;i<arr.size();i++){
        if(arr[(i-1)%n]>arr[i%n]){
            count++;
        }
    }
    return count==1;
}

int main(){
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(6);


    Check(arr);
    cout<<Check(arr);
    return 0;
}