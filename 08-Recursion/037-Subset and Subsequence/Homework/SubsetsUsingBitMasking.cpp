#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> subset(vector<int>& arr){
    int size=arr.size();
    int subsetcounts=(1<<size); //2^size
    vector<vector<int>> ans;
    for(int mask=0;mask<subsetcounts;mask++){
        vector<int>subset;
        for(int i=0;i<size;i++){
            if((mask&(1<<i))!=0){
                subset.push_back(arr[i]);
            }
        }
        ans.push_back(subset);
    }
    return ans;
}

int main(){
     vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    vector<vector<int>> result = subset(arr);
    for (const auto& subset : result) {
        cout << "[ ";
        for (const auto& num : subset) {
            cout << num << " ";
        }
        cout << "]" ;
    }
}