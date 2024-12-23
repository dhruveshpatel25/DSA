#include<iostream>
#include<vector>
using namespace std;

void Merge(vector<int>& arr1,vector<int>& arr2,vector<int>& arr3){

    //pointer for array 1
    int i=0;

    //pointer for array 2
    int j=0;

    //pointer for new array
    int k=0;

    //iterate till both the pointer are inside the array
    while(i<arr1.size() && j<arr2.size()){

        //if the element from 1st array is smaller
        if(arr1[i]<arr2[j]){

            //push the element of 1st array in new array
            arr3[k++]=arr1[i++];
        }
        //if the element of 2nd array is smaller
        else{

            //push the 2nd element array in new array
            arr3[k++]=arr2[j++];
        }
    }

    //iterate only for 1st array if 2nd array is over
    while(i<arr1.size()){
        arr3[k++]=arr1[i++];
    }

    //iterate only for 2nd array if 1st array is over
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