#include<iostream>
#include<vector>
using namespace std;

vector<int> WavePrint(vector<vector<int>>& arr, int rows, int cols){
    vector<int> ans;
    for(int col=0;col<cols;col++){
        if(col&1){
            for(int row=rows-1; row>=0;row--){
                ans.push_back(arr[row][col]);
            }
        }else{
            for(int row=0; row<rows; row++){
                ans.push_back(arr[row][col]);
            }
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> arr;
    arr.push_back(vector<int>{1,2,3});
    arr.push_back(vector<int>{4,5,6});
    arr.push_back(vector<int>{7,8,9});
    vector<int> result=WavePrint(arr,3,3);

    for(int i: result){
        cout<<i<<" ";
    }
    return 0;

}