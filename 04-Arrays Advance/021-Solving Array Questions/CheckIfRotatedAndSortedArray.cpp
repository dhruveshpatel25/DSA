#include<iostream>
#include<vector>
using namespace std;

bool Check(vector<int>& arr){
    int count=0;

    //to check for rotation
    int n=arr.size()-1;
    for(int i=1;i<arr.size();i++){

        //check the previous element with the current element(as it can be rotated so we need to use modulus)
        if(arr[(i-1)%n]>arr[i%n]){

            //increase if only the previous element is greater
            count++;
        }
    }

    //only one time the count will increase in rotated and sorted array when we reach the last element
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