#include<iostream>
#include<map>
#include<unordered_map>
#include<vector>
using namespace std;

int maximuFrequency(vector<int> &arr,int n){
    unordered_map<int,int> count;

    int maxfreq=0;
    int maxans=0;
    for(int i=0;i<arr.size();i++){
        count[arr[i]]++;
        maxfreq=max(maxfreq,count[arr[i]]);
    }
    for(int i=0;i<arr.size();i++){
        if(maxfreq==count[arr[i]]){
            maxans=arr[i];
        }
    }
    return maxans;
}

int main() {
    vector<int> arr = {1, 2, 2, 3, 3, 3, 3, 3, 4, 4, 4, 4};
    int n = arr.size();
    int maxFrequencyElement = maximuFrequency(arr, n);
    cout << "Element with maximum frequency: " << maxFrequencyElement << endl;
    return 0;
}
