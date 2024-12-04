/*Find Unique
You have been given an integer array/list(ARR) of size N. Where N is equal to [2M + 1].

Now, in the given array/list, 'M' numbers are present twice and one number is present only once.

You need to find and return that number which is unique in the array/list.

 Note:
Unique element is always present in the array/list according to the given condition.
https://www.naukri.com/code360/problems/find-unique_625159?source=youtube&campaign=love_babbar_codestudio1&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio1*/
#include<iostream>
using namespace std;

int FindUnique(int arr[], int size){
    int ans=0;
    for(int i=0;i<size;i++){

        //XOR to find the unique number
        ans=ans^arr[i];
    }
    return ans;
}

int main(){
    int arr[5]={1,2,3,2,1};
    FindUnique(arr,5);
    int ans=FindUnique(arr,5);
    cout<<"The Unique Value is: "<<ans;
}