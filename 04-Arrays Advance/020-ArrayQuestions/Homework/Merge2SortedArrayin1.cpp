#include<iostream>
#include<vector>
using namespace std;

void Merge(vector<int>& arr1, vector<int>&arr2){
    int i=0;
    int j=0;
    int temp=-1;
    while(i<arr1.size() && j<arr2.size()){
        if(arr1[i]>arr2[j] && arr1[i]!=0){
            temp=arr1[i];
            arr1[i]=arr2[j];
            arr2[j]=temp;
            i++;
        }else if(arr1[i]==0){
            arr1[i++]=arr2[j++];
        }else{
            i++;
        }
    }
}

int main(){
    vector<int> arr1;
    arr1.push_back(1);
    arr1.push_back(2);
    arr1.push_back(3);
    arr1.push_back(0);
    arr1.push_back(0);
    arr1.push_back(0);

    vector<int> arr2;
    arr2.push_back(2);
    arr2.push_back(5);
    arr2.push_back(6);

    Merge(arr1,arr2);
    for(int i=0; i<arr1.size(); i++){
        cout<<arr1[i]<<" ";
    }
    return 0;
}