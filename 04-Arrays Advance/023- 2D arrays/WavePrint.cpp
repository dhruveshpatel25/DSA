/*Print Like A Wave
For a given two-dimensional integer array/list ‘ARR’ of size (N x M), print the ‘ARR’ in a sine wave order, i.e., print the first column top to bottom, next column bottom to top, and so on.

For eg:-
The sine wave for the matrix:-
1 2
3 4
will be [1, 3, 4, 2].
[↓ → ↓]
[↓ ↑ ↓]
[→ ↑ →]
https://www.naukri.com/code360/problems/print-like-a-wave_893268*/
#include<iostream>
#include<vector>
using namespace std;

vector<int> WavePrint(vector<vector<int>>& arr, int rows, int cols){
    vector<int> ans;

    //iterate the index row-wise
    for(int col=0;col<cols;col++){

        //check which no. the column is 
        if(col&1){

            //if the column is odd numbered then iterate in upwards direction
            for(int row=rows-1; row>=0;row--){
                ans.push_back(arr[row][col]);
            }
        }else{

            //if the column is even numbered then iterate in downwards direction
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