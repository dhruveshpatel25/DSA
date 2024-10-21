#include<iostream>
#include<vector>
using namespace std;

bool BinarySearch(vector<vector<int>>& matrix, int target ){
    int row=matrix.size();
    int col=matrix[0].size();

    int rowIndex=0;
    int colIndex=col-1;
    while(rowIndex < row && colIndex >= 0){
        int element = matrix[rowIndex][colIndex];
        if(element==target){
            return 1;
        }
        else if(element > target){
            colIndex--;
        }else{
            rowIndex++;
        }
    }
    return 0;
}

int main(){
    vector<vector<int>> matrix;
    matrix.push_back({1,4,7,11,15});
    matrix.push_back({2,5,8,12,19});
    matrix.push_back({3,6,9,16,22});
    matrix.push_back({10,13,14,17,24});
    matrix.push_back({18,21,23,26,30});
    int target;
    cout<<"Enter the element to be searched: ";
    cin>>target;
    bool result = BinarySearch(matrix,target);
    if(result){
        cout<<"The element is present";
    }else{
        cout<<"The element is not present";
    }
}