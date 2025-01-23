/*Job Sequencing Problem
You are given three arrays: id, deadline, and profit, where each job is associated with an ID, a deadline, and a profit. Each job takes 1 unit of time to complete, and only one job can be scheduled at a time. You will earn the profit associated with a job only if it is completed by its deadline.

Your task is to find:
    The maximum number of jobs that can be completed within their deadlines.
    The total maximum profit earned by completing those jobs.
Examples :

Input: id = [1, 2, 3, 4], deadline = [4, 1, 1, 1], profit = [20, 1, 40, 30]
Output: [2, 60]
Explanation: Job1 and Job3 can be done with maximum profit of 60 (20+40).

Input: id = [1, 2, 3, 4, 5], deadline = [2, 1, 2, 1, 1], profit = [100, 19, 27, 25, 15]
Output: [2, 127]
Explanation: Job1 and Job3 can be done with maximum profit of 127 (100+27).

Input: id = [1, 2, 3, 4], deadline = [3, 1, 2, 2], profit = [50, 10, 20, 30]
Output: [3, 100]
Explanation: Job1, Job3 and Job4 can be completed with a maximum profit of 100 (50 + 20 + 30).
https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1*/
#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> a,pair<int,int> b){
    return a.first>b.first;
}

vector<int> JobSequencing(vector<int> &id, vector<int> &deadline,vector<int> &profit) {
    int n=deadline.size();
    vector<pair<int,int>> jobs;
    for(int i=0;i<n;i++){
        pair<int,int> p=make_pair(profit[i],deadline[i]);
        jobs.push_back(p);
    }

    sort(jobs.begin(),jobs.end(),cmp);

    int maxDeadline=0;
    for(int i=0;i<n;i++){
        maxDeadline=max(maxDeadline,jobs[i].second);
    }

    vector<int> schedule(maxDeadline+1,-1);

    int totalJobs=0;
    int totalProfit=0;
    for(int i=0;i<n;i++){
        for(int j=jobs[i].second;j>0;j--){
            if(schedule[j]==-1){
                schedule[j]=i;
                totalJobs++;
                totalProfit=totalProfit+jobs[i].first;
                break;
            }
        }
    }

    return {totalJobs,totalProfit};
}

int main() {
    vector<int> id = {1, 2, 3, 4};
    vector<int> deadline = {4, 1, 1, 1};
    vector<int> profit = {20, 1, 40, 30};

    vector<int> result = JobSequencing(id, deadline, profit);

    cout << "Maximum number of jobs: " << result[0] << endl;
    cout << "Total maximum profit: " << result[1] << endl;

    return 0;
}