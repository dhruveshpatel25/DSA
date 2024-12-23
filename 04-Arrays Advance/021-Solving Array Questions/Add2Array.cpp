/*Sum Of Two Arrays
You are given two numbers 'A' and 'B' in the form of two arrays (A[] and B[]) of lengths 'N' and 'M' respectively, where each array element represents a digit. You need to find the sum of these two numbers and return this sum in the form of an array.
Note:
1. The length of each array is greater than zero.
2. The first index of each array is the most significant digit of the number. For example, if the array A[] = {4, 5, 1}, then the integer represented by this array is 451 and array B[] = {3, 4, 5} so the sum will be 451 + 345 = 796. So you need to return {7, 9, 6}.
3. Both numbers do not have any leading zeros in them. And subsequently, the sum should not contain any leading zeros.
https://www.naukri.com/code360/problems/sum-of-two-arrays_893186*/
#include<iostream>
#include<vector>
using namespace std;

void reverse(vector<int>& ans){
    int start=0;
    int end=ans.size()-1;
    while(start<=end){
        swap(ans[start++],ans[end--]);
    }
}

void Add(vector<int>& arr1,int size1, vector<int>& arr2, int size2, vector<int>& ans){

    //pointer for the 1st array
    int i=size1-1;

    //pointer for the 2nd array
    int j=size2-1;

    //sum of the 2 number
    int sum=0;

    //carry if the sum is greater than 10
    int carry=0;

    //iterate for both the array
    while(i>=0 && j>=0){

        //sum = 1st array element + 2nd element array + carry(if any)
        sum=arr1[i--]+arr2[j--]+carry;

        //carry will the first digit of sum
        carry=sum/10;

        //sum will be the last digit of sum
        sum=sum%10;

        //push the sum in new array
        ans.push_back(sum);
    }

    //iterate if only 1st array is left
    while(i>=0){

        //sum = element of array + carry(if any)
        sum=arr1[i--]+carry;

        //carry will the first digit of sum
        carry=sum/10;

        //sum will be the last digit of sum
        sum=sum%10;

        //push the sum in new array
        ans.push_back(sum);
    }

    //iterate if only 2nd array is left
    while(j>=0){

        //sum = element of array + carry(if any)
        sum=arr2[j--]+carry;

        //carry will the first digit of sum
        carry=sum/10;

        //sum will be the last digit of sum
        sum=sum%10;

        //push the sum in new array
        ans.push_back(sum);
    }

    //if there is any carry left at last
    while(carry!=0){

        //sum = carry
        int sum=carry;

        //carry will the first digit of sum
        carry=sum/10;

        //sum will be the last digit of sum
        sum=sum%10;

        //push the sum in new array
        ans.push_back(sum);
    }

    //reverse the new array to get correct answer
    return reverse(ans);
}

int main(){
    vector<int> arr1;
    arr1.push_back(1);
    arr1.push_back(2);
    arr1.push_back(3);

    vector<int> arr2;
    arr2.push_back(4);
    arr2.push_back(5);
    arr2.push_back(6);
    
    vector<int> ans;

    Add(arr1,3,arr2,3,ans);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}