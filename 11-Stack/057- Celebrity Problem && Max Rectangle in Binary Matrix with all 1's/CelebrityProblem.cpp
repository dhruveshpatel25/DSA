/*The Celebrity Problem
A celebrity is a person who is known to all but does not know anyone at a party. A party is being organized by some people.  A square matrix mat (n*n) is used to represent people at the party such that if an element of row i and column j is set to 1 it means ith person knows jth person. You need to return the index of the celebrity in the party, if the celebrity does not exist, return -1.
Note: Follow 0-based indexing.

Examples:
Input: mat[][] = [[0 1 0], [0 0 0], [0 1 0]]
Output: 1
Explanation: 0th and 2nd person both know 1. Therefore, 1 is the celebrity.

Input: mat[][] = [[0 1], [1 0]]
Output: -1
Explanation: The two people at the party both know each other. None of them is a celebrity.

Input: mat[][] = [[0]]
Output: 0
https://www.geeksforgeeks.org/problems/the-celebrity-problem/1?page=1&category%5B%5D=Stack&sortBy=*/
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

bool knows(vector<vector<int>>& M,int a,int b,int n){
    if(M[a][b]==1){
        return true;
    }else{
        return false;
    }
}

int celebrity(vector<vector<int>>& M,int n){
    stack<int> stk;

    //push all the index in stack
    for(int i=0;i<n;i++){
        stk.push(i);
    }

    //till there is only one element left
    while(stk.size()>1){

        //take 1st person
        int a=stk.top();
        stk.pop();

        //take 2nd person
        int b=stk.top();
        stk.pop();

        //check if 1st person knows 2nd person
        if(knows(M,a,b,n)){

            //if yes then 1st person cant be celebrity and 2nd becomes potential celebrity
            stk.push(b);
        }else{

            //if no then 2nd person cant be celebrity as he cant be unknown
            stk.push(a);
        }

        //now take the top value
        int ans=stk.top();
        int zerocount=0;

        //check for the number of 0's it has
        for(int i=0;i<n;i++){

            //iterate complete row and count 0 
            if(M[ans][i]==0){
                zerocount++;
            }
        }

        //if it is equal to number of people that means it is potential celebrity
        if(zerocount!=n){
            return -1;
        }
        int onecount=0;

        //check for the number of 1's it has
        for(int i=0;i<n;i++){

            //iterate complete column and count 1
            if(M[i][ans]==1){
                onecount++;
            }
        }

        //if it is equal to number of people-1(as diagonal in matrix will be 0)
        if(onecount!=n-1){
            return -1;
        }
        return ans;
    }
}

int main() {
    vector<vector<int>> M = {
        {0, 1, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0},
        {0, 0, 1, 0}
    };

    int n = M.size();
    int potential_celebrity = celebrity(M, n);

    if (potential_celebrity != -1) {
        cout << "Potential celebrity found at index: " << potential_celebrity << endl;
    } else {
        cout << "No celebrity found." << endl;
    }

    return 0;
}