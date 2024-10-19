#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int findAllDuplicates( vector<int> arr){
    unordered_set<int> seen;
    unordered_set<int> duplicates;
    for(int num:arr){
        if(seen.find(num)!=seen.end()){
            duplicates.insert(num);
        }else{
            seen.insert(num);
        }
    }
    for(int num:duplicates){
        cout<<num<<" ";
    }
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 1, 2, 6, 7, 8, 3};
    findAllDuplicates(arr);
    return 0;
}