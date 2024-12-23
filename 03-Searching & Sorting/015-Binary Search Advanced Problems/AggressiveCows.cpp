/*Aggressive Cows
You are given an array 'arr' consisting of 'n' integers which denote the position of a stall.
You are also given an integer 'k' which denotes the number of aggressive cows.
You are given the task of assigning stalls to 'k' cows such that the minimum distance between any two of them is the maximum possible.
Print the maximum possible minimum distance.

Example:
Input: 'n' = 3, 'k' = 2 and 'arr' = {1, 2, 3}
Output: 2
Explanation: The maximum possible minimum distance will be 2 when 2 cows are placed at positions {1, 3}. Here distance between cows is 2.
https://www.naukri.com/code360/problems/aggressive-cows_1082559
*/
#include <bits/stdc++.h> 
using namespace std;

bool isPossible(vector<int> &stalls,int cows,int mid,int size){
    int cowCount=1;
    int lastPos=stalls[0];
    for(int i=0;i<size;i++){
        if(stalls[i]-lastPos>=mid){
            cowCount++;
            if(cowCount==cows){
                return true;
            }
            lastPos=stalls[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls,int cows){
    sort(stalls.begin(),stalls.end());
    int start=0;
    int size=stalls.size();
    int end=stalls[size-1];
    int ans=-1;
    while(start<=end){
        int mid=start+((end-start)/2);
        if(isPossible(stalls,cows,mid,size)){
            ans=mid;
            start=mid+1;
        }else{
            end=mid-1;
        }
    }
    return ans;
}

int main() {
    int n, cows;
    cout << "Enter the number of stalls: ";
    cin >> n;

    vector<int> stalls(n);
    cout << "Enter the positions of stalls: ";
    for (int i = 0; i < n; i++) {
        cin >> stalls[i];
    }

    cout << "Enter the number of cows: ";
    cin >> cows;

    int result = aggressiveCows(stalls, cows);
    cout << "The largest minimum distance is: " << result << endl;

    return 0;
}