/*Count derangements
A Derangement is a permutation of ‘N’ elements, such that no element appears in its original position. For example, an instance of derangement of {0, 1, 2, 3} is {2, 3, 1, 0}, because 2 present at index 0 is not at its initial position which is 2 and similarly for other elements of the sequence.
Given a number ‘N’, find the total number of derangements possible of a set of 'N’ elements.

Note:
The answer could be very large, output answer %(10 ^ 9 + 7).
https://www.naukri.com/code360/problems/count-derangements_873861*/
#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

long long int solve(int n){

    // Base case: No derangements for 1 element
    if (n == 1) {
        return 0; 
    }

    //Base case: 1 derangement for 2 elements
    if (n == 2) {
        return 1; 
    }

    //if size of vector is 1 then u cant dearrange
    long long int prev2=0;

    //if size of vector is 2 only 1way to dearrange
    long long int prev1=1;

    //f(n)=(n-1)*(f(n-1)+f(n-2))
    //when swapping ith element with 0th element there would be (n-2) possiblity to solve
    //when just placing 0th element at ith index there would be (n-1) possibilty to solve
    for(int i=3;i<=n;i++){
        long long int ans=(((i-1)%MOD)*((prev1%MOD)+(prev2%MOD))%MOD);
        prev2=prev1;
        prev1=ans;
    }
    return prev1;
}

long long int countDerangements(int n){
    return solve(n);
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