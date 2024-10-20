#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int>& arr, int index, vector<vector<int>>& ans){
    if(index>=arr.size()){
        ans.push_back(arr);
        return;
    }
    for(int i= index ;i<arr.size();i++){
        swap(arr[index],arr[i]);
        solve(arr,index+1,ans);
        //backtracking  
        swap(arr[i],arr[index]);
    }
}

vector<vector<int>> permutation(vector<int>& arr){
    vector<vector<int>> ans;
    int index=0;
    if(arr.size()==0){
        return ans;
    }
    solve(arr,index,ans);
    return ans;
}

int main(){
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> result = permutation(arr);
    
    for(const auto& perm : result){
        cout << "[ ";
        for(const auto& num : perm){
            cout << num << " ";
        }
        cout << "]" ;
    }

    return 0;
}