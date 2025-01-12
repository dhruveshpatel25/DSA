/*Dice throw
Given n dice each with m faces. Find the number of ways to get sum x which is the summation of values on each face when all the dice are thrown.

Example:

Input: m = 6, n = 3, x = 12
Output: 25
Explanation: There are 25 total ways to get the Sum 12 using 3 dices with faces from 1 to 6.

Input: m = 2, n = 3, x = 6
Output: 1
Explanation: There is only 1 way to get the Sum 6 using 3 dices with faces from 1 to 2. All the dices will have to land on 2.
https://www.geeksforgeeks.org/problems/dice-throw5349/1*/
#include<bits/stdc++.h>
using namespace std;

int solve(int dices,int faces,int target){
    vector<int> curr(target+1,0);
    vector<int> prev(target+1,0);

    prev[0]=1;
    for(int d=1;d<=dices;d++){
        for(int t=1;t<=target;t++){
            int ans=0;
            for(int i=1;i<=faces;i++){
                if(t-i>=0){
                    ans=ans+prev[t-i];
                }
            }
            curr[t]=ans;
        }
        prev=curr;
    }
    return prev[target];
}

int noOfWays(int dices, int faces, int target) {
    return solve(dices,faces,target);
}

int main() {
    // Input the number of dice, faces, and target sum
    cout << "Enter the number of dice: ";
    int dices;
    cin >> dices;

    cout << "Enter the number of faces on each die: ";
    int faces;
    cin >> faces;

    cout << "Enter the target sum: ";
    int target;
    cin >> target;

    // Call the function to calculate the number of ways
    int result = noOfWays(dices, faces, target);

    // Output the result
    cout << "The number of ways to achieve the target sum is: " << result << endl;

    return 0;
}