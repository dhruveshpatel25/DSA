/*Maximum Meetings in One Room
There is one meeting room in a firm. There are N meetings in the form of (S[i], F[i]) where S[i] is the start time of meeting i and F[i] is the finish time of meeting i. The task is to find the maximum number of meetings that can be accommodated in the meeting room. You can accommodate a meeting if the start time of the meeting is strictly greater than the finish time of the previous meeting. Print all meeting numbers.
Note: If two meetings can be chosen for the same slot then choose meeting that finishes earlier.

Example 1:
Input:
N = 6
S = {1,3,0,5,8,5}
F = {2,4,6,7,9,9} 
Output:
{1,2,4,5}
Explanation:
We can attend the 1st meeting from (1 to 2), then the 2nd meeting from (3 to 4), then the 4th meeting from (5 to 7), and the last meeting we can attend is the 5th from (8 to 9). It can be shown that this is the maximum number of meetings we can attend.

Example 2:
Input:
N = 1
S = {3}
F = {7}
Output:
{1}
Explanation:
Since there is only one meeting, we can attend the meeting.
https://www.geeksforgeeks.org/problems/maximum-meetings-in-one-room/1*/
#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> a,pair<int,int> b){
    return a.second<b.second;
}

vector<int> maxMeetings(int n,vector<int>& start, vector<int>& end) {
    vector<pair<int,int> > meeting;
    for(int i=0;i<start.size();i++){
        pair<int,int> p=make_pair(start[i],end[i]);
        meeting.push_back(p);
    }

    sort(meeting.begin(),meeting.end(),cmp);

    vector<int> result;
    int ansEnd=meeting[0].second;

    result.push_back(1);

    for(int i=1;i<start.size();i++){
        if(meeting[i].first>ansEnd){
            result.push_back(i+1);
            ansEnd=meeting[i].second;
        }
    }
    return result;
}

int main() {
    int N = 6;
    vector<int> S = {1, 3, 0, 5, 8, 5};
    vector<int> F = {2, 4, 6, 7, 9, 9};

    vector<int> result = maxMeetings(N, S, F);

    // Output the selected meeting numbers
    cout << "{";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1) cout << ",";
    }
    cout << "}" << endl;

    return 0;
}