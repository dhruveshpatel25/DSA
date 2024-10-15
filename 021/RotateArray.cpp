#include<iostream>
#include<vector>
using namespace std;

void Rotate(vector<int>& arr,int k){
    int n= arr.size();
    vector<int> temp(n);
    for(int i=0; i<n;i++){
        temp[(i+k)%n]=arr[i];
    }
    arr=temp;
}
int main(){
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(6);


    Rotate(arr,2);
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    return 0;
} 