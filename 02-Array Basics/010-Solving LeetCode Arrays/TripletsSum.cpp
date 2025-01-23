/* 3Sum
You are given an array/list ARR consisting of N integers. Your task is to find all the distinct triplets present in the array which adds up to a given number K.

An array is said to have a triplet {ARR[i], ARR[j], ARR[k]} with sum = 'K' if there exists three indices i, j and k such that i!=j, j!=k and i!=j and ARR[i] + ARR[j] + ARR[k] = 'K'.

Note:
1. You can return the list of values in any order. For example, if a valid triplet is {1, 2, -3}, then {2, -3, 1}, {-3, 2, 1} etc is also valid triplet. Also, the ordering of different triplets can be random i.e if there are more than one valid triplets, you can return them in any order.
2. The elements in the array need not be distinct.
3. If no such triplet is present in the array, then return an empty list, and the output printed for such a test case will be "-1".
https://www.naukri.com/code360/problems/triplets-with-given-sum_893028*/
#include<iostream>
using namespace std;

void PairSum(int arr[],int size,int S){
    for(int i=0;i<size;i++){

        //start j for particular i
        for(int j=i+1;j<size;j++){

            //start k for particular j
            for(int k=j+1;k<size;k++){

                //if the sum is expected sum then print it
                if(arr[i]+arr[j]+arr[k]==S){
                    cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<endl;
                    break;
                }
            }
        }
    }
}
int main(){
    int arr[5]={1,2,3,4,5};
    int S=12;
    PairSum(arr,5,12);
}