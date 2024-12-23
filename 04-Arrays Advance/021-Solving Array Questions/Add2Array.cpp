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