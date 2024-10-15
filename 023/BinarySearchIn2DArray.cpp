#include<iostream>
#include<vector>
using namespace std;
bool BinarySearch(vector<vector<int>>& matrix, int target ){
    int row=matrix.size();
    int col=matrix[0].size();

    int start=0;
    int end=row*col-1;
    while(start<=end){
        int mid=start+((end-start)/2);
        int element=matrix[mid/col][mid%col];
        if(element==target){
            return 1;
        }else if(element < target){
            start=mid+1;
        }else{
            end=mid-1;
        }
    }
    return 0;
}

int main(){
    vector<vector<int>> matrix;
    matrix.push_back({1,2,3});
    matrix.push_back({4,5,6});
    matrix.push_back({7,8,9});
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