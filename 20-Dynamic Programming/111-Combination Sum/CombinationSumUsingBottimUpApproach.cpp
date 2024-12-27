/*Combination Sum IV
You are given an array of distinct integers and you have to tell how many different ways of selecting the elements from the array are there such that the sum of chosen elements is equal to the target number tar.
Note: Two ways are considered the same if for every index the contents of both the ways are equal example way1=[1,2,3,1] and way2= [1,2,3,1] both way1 and way 2 are the same.
But if way1 =[1,2,3,4] and way2= [4,3,2,1] then both ways are different.
Input is given such that the answer will fit in a 32-bit integer. 

For Example:
If N = 3 and tar = 5 and array elements are [1,2,5] then the number of possible ways of making sum = 5 are:
(1,1,1,1,1)
(1,1,1,2)
(1,2,1,1)
(2,1,1,1)
(1,1,2,1)
(2,2,1)
(1,2,2)
(2,1,2)
(5)
Hence the output will be 9.
https://www.naukri.com/code360/problems/number-of-ways_3755252*/
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &num, int tar){
    vector<int> dp(tar+1,0);

    //if target is becomes 0
    dp[0]=1;

    //iterate for all target
    for(int i=1;i<=tar;i++){

        //for all the elements in the array
        for(int j=0;j<num.size();j++){

            //check if it is feasible
            if(i-num[j]>=0){
                dp[i]+=dp[i-num[j]];
            }
        }
    }
    return dp[tar];
}

int findWays(vector<int> &num, int tar){
    int ans=solve(num,tar);
    return ans;
}
int main() {
    int n, tar;

    // Input the number of elements in the array
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> num(n);

    // Input the array elements
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    // Input the target sum
    cout << "Enter the target sum: ";
    cin >> tar;

    // Call the findWays function
    int result = findWays(num, tar);

    // Output the result
    cout << "The number of ways to form the target sum is: " << result << endl;

    return 0;
}