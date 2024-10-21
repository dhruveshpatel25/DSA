#include<iostream>
#include<vector>
using namespace std;

void Merge(vector<int>& arr1,vector<int>& arr2,vector<int>& arr3){
    int i=0;
    int j=0;
    int k=0;
    while(i<arr1.size() && j<arr2.size()){
        if(arr1[i]<arr2[j]){
            arr3[k++]=arr1[i++];
        }else{
            arr3[k++]=arr2[j++];
        }
    }
    while(i<arr1.size()){
        arr3[k++]=arr1[i++];
    }
    while(j<arr2.size()){
        arr3[k++]=arr2[j++];
    }
}

int main(){
    vector<int> arr1;
    arr1.push_back(1);
    arr1.push_back(3);
    arr1.push_back(5);
    arr1.push_back(7);
    arr1.push_back(9);

    vector<int> arr2;
    arr2.push_back(2);
    arr2.push_back(4);
    arr2.push_back(6);
    arr2.push_back(8); 

    vector<int> arr3(arr1.size()+arr2.size());
    Merge(arr1,arr2,arr3);

    for(int i=0; i<arr3.size(); i++){
        cout<<arr3[i]<<" ";
    }
    return 0;
}