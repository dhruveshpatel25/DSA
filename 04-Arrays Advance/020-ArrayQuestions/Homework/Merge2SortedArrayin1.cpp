#include<iostream>
#include<vector>
using namespace std;

void Merge(vector<int>& arr1, vector<int>&arr2){

    //pointer for 1st array
    int i=0;

    //pointer for 2nd array
    int j=0;

    //to store the value
    int temp=-1;

    //iterate for both the pointer
    while(i<arr1.size() && j<arr2.size()){

        //check if the element of 1st array is greater than the 2nd array
        //also check if the element in 1st array is not zero
        if(arr1[i]>arr2[j] && arr1[i]!=0){

            //store the element
            temp=arr1[i];

            //push the 2nd array element(smaller)
            arr1[i]=arr2[j];

            //now push the larger element in second array so we can check it again
            arr2[j]=temp;

            //increase the first array pointer
            i++;
        }
        
        //if there exist a 0 in the 1st array
        else if(arr1[i]==0){

            //just push the 2nd array element in 1st array
            arr1[i++]=arr2[j++];
        }
        //if the element in 1st element is smaller just move the pointer ahead
        else{
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