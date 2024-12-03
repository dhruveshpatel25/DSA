#include<bits/stdc++.h>
using namespace std;

void Sort012(vector<int>& arr,int size) {
    int zeroCount = 0;
    int oneCount = 0; 
    int twoCount = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == 0) {
            zeroCount++;
        } else if (arr[i] == 1) {
            oneCount++;
        } else {
            twoCount++;
        }
    }
    int index = 0;
    for (int i = 0; i < zeroCount; i++) {
        arr[index++] = 0;
    }
    for (int i = 0; i < oneCount; i++) {
        arr[index++] = 1;
    }
    for (int i = 0; i < twoCount; i++) {
        arr[index++] = 2;
    }
}

int main(){
    int size;
    cout<<"Enter the size of array: ";
    cin>>size;
    vector<int> arr(size);
    cout<<"Enter the elements: ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    Sort012(arr,size);
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}