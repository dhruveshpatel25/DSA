/*Activity Selection
Given some activities with their start and end day given in array start[] and end[]. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a given day.
Note : Duration of the activity includes both starting and ending day.

Examples:

Input: start[] = [2, 1], end[] = [2, 2]
Output: 1
Explanation: A person can perform only one of the given activities.

Input: start[] = [1, 3, 2, 5], end[] = [2, 4, 3, 6]
Output: 3
Explanation: A person can perform activities 1, 2 and 4.

Input: start[] = [1, 3, 0, 5, 8, 5], end[] = [2, 4, 6, 7, 9, 9]
Output: 4
Explanation: A person can perform activities 0, 1, 3, and 4.
https://www.geeksforgeeks.org/problems/activity-selection-1587115620/1*/
#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int> a,pair<int,int> b){
    return a.second<b.second;
}

int activitySelection(vector<int> &start, vector<int> &end) {
    vector<pair<int,int> > activity;

    //iterate complete array
    for(int i=0;i<start.size();i++){

        //make pair with start and end time
        pair<int,int> p=make_pair(start[i],end[i]);

        //push in pair array
        activity.push_back(p);
    }

    //sort it according to end time
    sort(activity.begin(),activity.end(),cmp);

    //including the first activity
    int count=1;
    int ansEnd=activity[0].second;

    //iterate the other activity
    for(int i=1;i<start.size();i++){

        //if start time of second activity is greater than the end time of previous activity then include the second meeting
        if(activity[i].first>ansEnd){
            count++;

            //update the end time
            ansEnd=activity[i].second;
        }
    }
    return count;
}

int main() {
    vector<int> start = {1,3,0,5,8,5};
    vector<int> end = {2,4,6,7,9,9};

    int result = activitySelection(start, end);
    cout << "Maximum number of activities that can be performed: " << result << endl;

    return 0;
}