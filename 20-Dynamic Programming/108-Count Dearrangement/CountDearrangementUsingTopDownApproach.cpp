/*Count derangements
A Derangement is a permutation of ‘N’ elements, such that no element appears in its original position. For example, an instance of derangement of {0, 1, 2, 3} is {2, 3, 1, 0}, because 2 present at index 0 is not at its initial position which is 2 and similarly for other elements of the sequence.
Given a number ‘N’, find the total number of derangements possible of a set of 'N’ elements.

Note:
The answer could be very large, output answer %(10 ^ 9 + 7).
https://www.naukri.com/code360/problems/count-derangements_873861*/
#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

long long int solve(int n,vector<long long int>& dp){

    //base case
    if(n==1){
        return 0;
    }

    //base case
    if(n==2){
        return 1;
    }

    //return the value for that element
    if(dp[n]!=-1){
        return dp[n];
    }

    //f(n)=(n-1)*(f(n-1)+f(n-2))
    //when swapping ith element with 0th element there would be (n-2) possiblity to solve
    //when just placing 0th element at ith index there would be (n-1) possibilty to solve
    dp[n] = (((n-1)%MOD)*((solve(n-1,dp)%MOD)+(solve(n-2,dp)%MOD))%MOD);
    return dp[n];
}
long long int countDerangements(int n) {
    vector<long long int>dp(n+1,-1);
    long long int ans=solve(n,dp);
    return ans;
}
int main() {
    int n;

    // Input the number of elements
    cout << "Enter the number of elements (N): ";
    cin >> n;

    // Call the function to calculate derangements
    long long int result = countDerangements(n);

    // Output the result
    cout << "The total number of derangements is: " << result << endl;

    return 0;
}