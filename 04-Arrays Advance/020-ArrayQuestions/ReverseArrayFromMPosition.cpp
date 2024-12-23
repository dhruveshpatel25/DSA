#include<iostream>
#include<vector>
using namespace std;

void Reverse(vector<int>& arr, int m){

    //start pointer from mth position
    int start=m+1;

    //end pointer from the last position in array
    int end=arr.size()-1;

    //iterate till they cross each other
    while(start<=end){

        //swap them
        swap(arr[start],arr[end]);

        //move the start pointer ahead
        start++;

        //move the end pointer behind
        end--;
    }
}

int main(){
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    int m=1;
    Reverse(arr,m);

    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}