#include<iostream>
#include<vector>
using namespace std;

void MoveZeros(vector<int>& arr){
    int i=0;

    //iterate the array
    for(int j=0;j<arr.size();j++){

        //check if current element is 0 or not
        if(arr[j]!=0){

            //if zero swap with the ith element
            swap(arr[j],arr[i]);

            //increase the count
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