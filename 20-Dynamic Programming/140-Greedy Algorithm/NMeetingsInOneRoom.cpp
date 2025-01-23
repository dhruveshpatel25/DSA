/*N meetings in one room
You are given timings of n meetings in the form of (start[i], end[i]) where start[i] is the start time of meeting i and end[i] is the finish time of meeting i. Return the maximum number of meetings that can be accommodated in a single meeting room, when only one meeting can be held in the meeting room at a particular time. 
Note: The start time of one chosen meeting can't be equal to the end time of the other chosen meeting.

Examples :
Input: start[] = [1, 3, 0, 5, 8, 5], end[] =  [2, 4, 6, 7, 9, 9]
Output: 4
Explanation: Maximum four meetings can be held with given start and end timings. The meetings are - (1, 2), (3, 4), (5,7) and (8,9)

Input: start[] = [10, 12, 20], end[] = [20, 25, 30]
Output: 1
Explanation: Only one meetings can be held with given start and end timings.

Input: start[] = [1, 2], end[] = [100, 99]
Output: 1
https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1*/
#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> a,pair<int,int> b){
    return a.second<b.second;
}

int maxMeetings(vector<int>& start, vector<int>& end) {
    vector<pair<int,int> > meeting;
    for(int i=0;i<start.size();i++){
        pair<int,int> p=make_pair(start[i],end[i]);
        meeting.push_back(p);
    }

    sort(meeting.begin(),meeting.end(),cmp);

    int count=1;
    int ansEnd=meeting[0].second;

    for(int i=1;i<start.size();i++){
        if(meeting[i].first>ansEnd){
            count++;
            ansEnd=meeting[i].second;
        }
    }
    return count;
}


int main() {
    // Test Case 1
    vector<int> start1 = {1, 3, 0, 5, 8, 5};
    vector<int> end1 = {2, 4, 6, 7, 9, 9};
    cout << "Test Case 1: Maximum Meetings = " << maxMeetings(start1, end1) << endl;

    // Test Case 2
    vector<int> start2 = {10, 12, 20};
    vector<int> end2 = {20, 25, 30};
    cout << "Test Case 2: Maximum Meetings = " << maxMeetings(start2, end2) << endl;

    // Test Case 3
    vector<int> start3 = {1, 2};
    vector<int> end3 = {100, 99};
    cout << "Test Case 3: Maximum Meetings = " << maxMeetings(start3, end3) << endl;

    // Additional Test Case 4
    vector<int> start4 = {1, 2, 3};
    vector<int> end4 = {4, 4, 4};
    cout << "Test Case 4: Maximum Meetings = " << maxMeetings(start4, end4) << endl;

    return 0;
}