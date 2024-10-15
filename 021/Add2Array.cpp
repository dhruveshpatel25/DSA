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
    int i=size1-1;
    int j=size2-1;
    int sum=0;
    int carry=0;
    while(i>=0 && j>=0){
        sum=arr1[i--]+arr2[j--]+carry;
        carry=sum/10;
        sum=sum%10;
        ans.push_back(sum);
    }
    while(i>=0){
        sum=arr1[i--]+carry;
        carry=sum/10;
        sum=sum%10;
        ans.push_back(sum);
    }
    while(j>=0){
        sum=arr2[j--]+carry;
        carry=sum/10;
        sum=sum%10;
        ans.push_back(sum);
    }
    while(carry!=0){
        int sum=carry;
        carry=sum/10;
        sum=sum%10;
        ans.push_back(sum);
    }
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