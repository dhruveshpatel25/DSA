/*Beautiful Triplets
Given a sequence of integers a, a triplet (a[i], a[j], a[k]) is beautiful if:
    i < j < k
    a[j] – a[i] = a[k] – a[j] = d
Given an increasing sequenc of integers and the value of d, count the number of beautiful triplets in the sequence.

Example
arr = [2, 2, 3, 4, 5]
d = 1
There are three beautiful triplets, by index: [i, j, k] = [0, 2, 3], [1, 2, 3], [2, 3, 4]. To test the first triplet, arr[j] – arr[i] = 3 – 2 = 1 and arr[k] – arr[j] = 4 – 3 = 1.

Function Description

Complete the beautifulTriplets function in the editor below.

beautifulTriplets has the following parameters:
    int d: the value to match
    int arr[n]: the sequence, sorted ascending
Returns
    int: the number of beautiful triplets
https://www.hackerrank.com/challenges/beautiful-triplets/problem*/
#include <bits/stdc++.h>
using namespace std;
int beautifulTriplets(int d, vector<int> arr) {

    //to check frequency of each element
    unordered_map<int,int> map;

    //counter for all the way possible
    int count=0;

    //iterate complete array
    for(int i:arr){

        //increase the count of that particular element (+= is done because there could be duplicate so we can form n combination for n duplicate)
        map[i]+=1;

        //check whether there exist sequence if it does add to count
        count+=map[i-d]*map[i-2*d];
    }
    return count;
}

int main() {
    // Input
    int n, d;
    cin >> n >> d; // Read the number of elements in the array and the difference d
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];  // Read the array elements
    }

    // Call the function and print the result
    int result = beautifulTriplets(d, arr);
    cout << result << endl;

    return 0;
}