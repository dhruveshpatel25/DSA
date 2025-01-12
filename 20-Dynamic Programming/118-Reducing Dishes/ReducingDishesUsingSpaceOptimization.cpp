/*Reducing Dishes
A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time.
Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level i.e. time[i] * satisfaction[i].
Return the maximum sum of like-time coefficient that the chef can obtain after preparing some amount of dishes.
Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.

Example 1:
Input: satisfaction = [-1,-8,0,5,-9]
Output: 14
Explanation: After Removing the second and last dish, the maximum total like-time coefficient will be equal to (-1*1 + 0*2 + 5*3 = 14).
Each dish is prepared in one unit of time.

Example 2:
Input: satisfaction = [4,3,2]
Output: 20
Explanation: Dishes can be prepared in any order, (2*1 + 3*2 + 4*3 = 20)

Example 3:
Input: satisfaction = [-1,-4,-5]
Output: 0
Explanation: People do not like the dishes. No dish is prepared.
https://leetcode.com/problems/reducing-dishes/description/*/
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& satisfaction){
    int n=satisfaction.size();

    //current array
    vector<int> curr(n+1,0);

    //next array
    vector<int> next(n+1,0);

    //from last row to first
    for(int index=n-1;index>=0;index--){

        //from index time to 0
        for(int time=index;time>=0;time--){

            //include current dish
            int include=satisfaction[index]*(time+1)+next[time+1];

            //exclude current dish
            int exclude=0+next[time];

            //save the maximum 
            curr[time]=max(include,exclude);
        }

        //iterate ahead
        next=curr;
    }
    return next[0];
}

int solve2(vector<int>& satisfaction){
    int n=satisfaction.size();
    vector<int> curr(n+1,0);

    //from last row to first row
    for(int index=n-1;index>=0;index--){

        //from time 0 to index time as data depend on its ahead index
        for(int time=0;time<=index;time++){

            //include dish
            int include=satisfaction[index]*(time+1)+curr[time+1];

            //exclude dish
            int exclude=0+curr[time];

            //save the maximum
            curr[time]=max(exclude,include);
        }
    }

    return curr[0];
}
int maxSatisfaction(vector<int>& satisfaction) {
    sort(satisfaction.begin(),satisfaction.end());
    return solve2(satisfaction);
}

int main() {
    // Test case: Example 1 from the problem statement
    vector<int> satisfaction = {-1, -8, 0, 5, -9};
    
    // Call the function and print the result
    cout << "Maximum like-time coefficient: " << maxSatisfaction(satisfaction) << endl;

    return 0;
}