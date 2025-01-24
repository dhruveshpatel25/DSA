/*Shop in Candy Store
In a candy store, there are n different types of candies available and the prices of all the N different types of candies are provided to you. You are now provided with an attractive offer.
For every candy you buy from the store and get K other candies ( all are different types ) for free. Now you have to answer two questions. Firstly, you have to find what is the minimum amount of money you have to spend to buy all the n different candies. Secondly, you have to find what is the maximum amount of money you have to spend to buy all the n different candies.
In both the cases you must utilize the offer i.e. you buy one candy and get k other candies for free.

Examples :
Input: n = 4, k = 2, candies[] = {3 2 1 4}
Output: 3 7
Explanation: As according to the offer if you buy one candy you can take at most two  more for free. So in the first case, you buy the candy which costs 1 and takes candies worth 3 and 4 for free, also you buy candy worth 2 as well.So min cost : 1+2 =3. In the second case, you can buy the candy which costs 4 and takes candies worth 1 and 2 for free, also you need to buy candy worth 3 as well. So max cost : 3+4 =7.

Input: n = 5, k = 4, candies[] = {3 2 1 4 5}
Output: 1 5
Explanation: For minimimum cost buy the candy with the cost 1 and get all the other candies for free. For maximum cost buy the candy with the cost 5 and get all other candies for free.
https://www.geeksforgeeks.org/problems/shop-in-candy-store1145/1*/
#include<bits/stdc++.h>
using namespace std;

vector<int> candyStore(int candies[], int N, int K){

    //sort the candies
    sort(candies,candies+N);
    int mini=0;
    int buy=0;
    int free=N-1;

    //minimum cost
    while(buy<=free){

        //add to the cost
        mini=mini+candies[buy];

        //iterate ahead
        buy++;

        //iterate behind "K" spaces
        free=free-K;
    }

    int maxi=0;
    buy=N-1;
    free=0;

    //maximum cost
    while(buy>=free){

        //add to the cost
        maxi=maxi+candies[buy];

        //iterate behind
        buy--;

        //iterate ahead "K" spaces
        free=free+K;
    }

    vector<int> ans;
    ans.push_back(mini);
    ans.push_back(maxi);

    return ans;
}

int main() {
    // Test Case 1
    int candies1[] = {3, 2, 1, 4};
    int N1 = 4, K1 = 2;
    vector<int> result1 = candyStore(candies1, N1, K1);
    cout << "Test Case 1: Min Cost = " << result1[0] << ", Max Cost = " << result1[1] << endl;

    // Test Case 2
    int candies2[] = {3, 2, 1, 4, 5};
    int N2 = 5, K2 = 4;
    vector<int> result2 = candyStore(candies2, N2, K2);
    cout << "Test Case 2: Min Cost = " << result2[0] << ", Max Cost = " << result2[1] << endl;

    // Test Case 3
    int candies3[] = {7, 3, 1, 9, 6};
    int N3 = 5, K3 = 1;
    vector<int> result3 = candyStore(candies3, N3, K3);
    cout << "Test Case 3: Min Cost = " << result3[0] << ", Max Cost = " << result3[1] << endl;

    // Test Case 4
    int candies4[] = {1, 2};
    int N4 = 2, K4 = 1;
    vector<int> result4 = candyStore(candies4, N4, K4);
    cout << "Test Case 4: Min Cost = " << result4[0] << ", Max Cost = " << result4[1] << endl;

    // Test Case 5
    int candies5[] = {1};
    int N5 = 1, K5 = 3;
    vector<int> result5 = candyStore(candies5, N5, K5);
    cout << "Test Case 5: Min Cost = " << result5[0] << ", Max Cost = " << result5[1] << endl;

    return 0;
}