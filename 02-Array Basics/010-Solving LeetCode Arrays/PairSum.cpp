/* Pair Sum
You are given an integer array 'ARR' of size 'N' and an integer 'S'. Your task is to return the list of all pairs of elements such that each sum of elements of each pair equals 'S'.

Note:
Each pair should be sorted i.e the first value should be less than or equals to the second value. 
Return the list of pairs sorted in non-decreasing order of their first value. In case if two pairs have the same first value, the pair with a smaller second value should come first.
https://www.naukri.com/code360/problems/pair-sum_697295*/
#include<iostream>
using namespace std;

void PairSum(int arr[],int size,int S){
    for(int i=0;i<size;i++){

        //iterate for particular i
        for(int j=i+1;j<size;j++){

            //check if expected sum then print the numbers
            if(arr[i]+arr[j]==S){
                cout<<arr[i]<<" "<<arr[j]<<endl;
            }
        }
    }
}
int main(){
    int arr[5]={1,2,3,4,5};
    int S=5;
    PairSum(arr,5,5);
}