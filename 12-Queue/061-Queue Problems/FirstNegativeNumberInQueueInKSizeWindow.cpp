/*First negative in every window of size k
Given an array arr[]  and a positive integer k, find the first negative integer for each and every window(contiguous subarray) of size k.

Note: If a window does not contain a negative integer, then return 0 for that window.

Examples:

Input: arr[] = [-8, 2, 3, -6, 10] , k = 2
Output: [-8, 0, -6, -6]
Explanation:
Window {-8, 2}: First negative integer is -8.
Window {2, 3}: No negative integers, output is 0.
Window {3, -6}: First negative integer is -6.
Window {-6, 10}: First negative integer is -6.

Input: arr[] = [12, -1, -7, 8, -15, 30, 16, 28] , k = 3
Output: [-1, -1, -7, -15, -15, 0] 
Explanation:
Window {12, -1, -7}: First negative integer is -1.
Window {-1, -7, 8}: First negative integer is -1.
Window {-7, 8, -15}: First negative integer is -7.
Window {8, -15, 30}: First negative integer is -15.
Window {-15, 30, 16}: First negative integer is -15.
Window {30, 16, 28}: No negative integers, output is 0.

Input: arr[] = [12, 1, 3, 5] , k = 3
Output: [0, 0] 
Explanation:
Window {12, 1, 3}: No negative integers, output is 0.
Window {1, 3, 5}: No negative integers, output is 0.
https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1*/
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

vector<int> firstNegative(vector<int> arr,int size,int windowsize){
    deque<int> deq;
    vector<int> ans;

    //pushing the first window size elements from array to doubly ended queue
    for(int i=0;i<windowsize;i++){

        //pushing only the negative number index
        if(arr[i]<0){
            deq.push_back(i);
        }
    }

    //first negative number of the window
    if(deq.size()>0){
        ans.push_back(arr[deq.front()]);
    }
    
    //if there exist no negative number in that window
    else{
        ans.push_back(0);
    }

    //now processing the next window
    for(int i=windowsize;i<size;i++){

        //remove the first element of the window
        if(!deq.empty() && i-deq.front()>=windowsize){
            deq.pop_front();
        }

        //adding the next element in the window
        if(arr[i]<0){
            deq.push_back(i);
        }

        //first negative number of that window
        if(deq.size()>0){
            ans.push_back(arr[deq.front()]);
        }

        //if there is no negative number in that window
        else{
            ans.push_back(0);
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {12, -1, -7, 8, -15, 30, 16, 28};
    int size = arr.size();
    int windowsize = 3;

    vector<int> result = firstNegative(arr, size, windowsize);

    cout << "First negative elements in each window: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}