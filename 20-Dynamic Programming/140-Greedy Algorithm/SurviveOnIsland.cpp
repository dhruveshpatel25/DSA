/*Check if it is possible to survive on Island
Geekina got stuck on an island. There is only one shop on this island and it is open on all days of the week except for Sunday. Consider following constraints:

N – The maximum unit of food you can buy each day.
S – Number of days you are required to survive.
M – Unit of food required each day to survive.
Currently, it’s Monday, and she needs to survive for the next S days.
Find the minimum number of days on which you need to buy food from the shop so that she can survive the next S days, or determine that it isn’t possible to survive.

Example 1:

Input: S = 10, N = 16, M = 2
Output: 2
Explaination: One possible solution is to 
buy a box on the first day (Monday), 
it’s sufficient to eat from this box up to 
8th day (Monday) inclusive. Now, on the 9th 
day (Tuesday), you buy another box and use 
the chocolates in it to survive the 9th and 
10th day.

Example 2:
Input: S = 10, N = 9, M = 8
Output: -1
Explaination: Let's start by detailing the days of the week and the net number of food units available after purchasing and consuming them:
Monday - Net 1 food unit available.
Tuesday - Net 2 food units available.
Wednesday - Net 3 food units available.
Thursday - Net 4 food units available.
Friday - Net 5 food units available.
Saturday - Net 6 food units available.
Sunday - 6 food units available and that is not sufficient amount of food units to survive and you can't buy more on Sunday.
https://www.geeksforgeeks.org/problems/check-if-it-is-possible-to-survive-on-island4922/1*/
#include<bits/stdc++.h>
using namespace std;

int minimumDays(int S, int N, int M) {
    int sunday=S/7;

    int buyingDays=S-sunday;
    int totalFood=S*M;
    int ans=0;

    if(totalFood%N==0){
        ans=totalFood/N;
    }else{
        ans=totalFood/N +1;
    }

    if(ans<=buyingDays){
        return ans;
    }else{
        return -1;
    }
}

int main() {
    // Test Case 1
    int S1 = 10, N1 = 16, M1 = 2;
    cout << "Test Case 1: Minimum days = " << minimumDays(S1, N1, M1) << endl;

    // Test Case 2
    int S2 = 1 , N2 = 9, M2 = 8;
    cout << "Test Case 2: Minimum days = " << minimumDays(S2, N2, M2) << endl;

    // Test Case 3
    int S3 = 20, N3 = 15, M3 = 5;
    cout << "Test Case 3: Minimum days = " << minimumDays(S3, N3, M3) << endl;

    // Test Case 4
    int S4 = 5, N4 = 6, M4 = 4;
    cout << "Test Case 4: Minimum days = " << minimumDays(S4, N4, M4) << endl;

    // Test Case 5
    int S5 = 7, N5 = 10, M5 = 2;
    cout << "Test Case 5: Minimum days = " << minimumDays(S5, N5, M5) << endl;

    return 0;
}