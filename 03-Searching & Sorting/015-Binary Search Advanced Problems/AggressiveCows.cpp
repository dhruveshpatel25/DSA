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

    //counter for no.of cows
    int cowCount=1;

    //first cow placed as possible solution
    int lastPos=stalls[0];

    //iterate the complete array
    for(int i=0;i<size;i++){

        //check for next stalls distancce
        if(stalls[i]-lastPos>=mid){

            //if greater then check for second cow
            cowCount++;

            //when the counter reaches maximum return true that it is possible to store
            if(cowCount==cows){
                return true;
            }

            //update the possible position
            lastPos=stalls[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls,int cows){

    //sort the array
    sort(stalls.begin(),stalls.end());

    //start pointer
    int start=0;

    //total no.of stalls
    int size=stalls.size();

    //end pointer   
    int end=stalls[size-1];

    //to store the maximum distance
    int ans=-1;

    //iterate till they cross eacch other
    while(start<=end){

        //find the middle value
        int mid=start+((end-start)/2);

        //check is possible to store the cows for middle value
        if(isPossible(stalls,cows,mid,size)){

            //if possible store middle value as possible solution
            ans=mid;

            //check if there could be more maximum distance
            start=mid+1;
        }
        
        //if not possible then check for lower value
        else{
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