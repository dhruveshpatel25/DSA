/*PRATA - Roti Prata
IEEE is having its AGM next week and the president wants to serve cheese prata after the meeting. The subcommittee members are asked to go to food connection and get P (P ≤ 1000) pratas packed for the function. The stall has L cooks (L ≤ 50) and each cook has a rank R (1 ≤ R ≤ 8). A cook with a rank R can cook 1 prata in the first R minutes 1 more prata in the next 2R minutes, 1 more prata in 3R minutes and so on (he can only cook a complete prata) (For example if a cook is ranked 2, he will cook one prata in 2 minutes one more prata in the next 4 mins an one more in the next 6 minutes hence in total 12 minutes he cooks 3 pratas in 13 minutes also he can cook only 3 pratas as he does not have enough time for the 4th prata). The webmaster wants to know the minimum time to get the order done. Please write a program to help him out.

Input
The first line tells the number of test cases. Each test case consist of 2 lines. In the first line of the test case we have P the number of prata ordered. In the next line the first integer denotes the number of cooks L and L integers follow in the same line each denoting the rank of a cook.

Output
Print an integer which tells the number of minutes needed to get the order done.

Example
Input:
3
10
4 1 2 3 4
8
1 1
8
8 1 1 1 1 1 1 1 1

Output:
12
36
1 
https://www.spoj.com/problems/PRATA/*/
#include<iostream>
#include<vector>
using namespace std;

bool isSufficientParathas(vector<int> chefs,int parathas,int maximumTime){

    //time taken to make paratha
    int time=0;

    //no.of paratha
    int count=0;

    //iterate for all chef
    for(int i=0;i<chefs.size();i++){

        //first paratha will take the rating amount time
        time=chefs[i];

        //as it increases by 2R,3R,... so we start with 2
        int j=2;

        //make parathas till maximum time reached
        while(time<=maximumTime){

            //increase everytime the paratha is possible
            count++;

            //increase the time respect to 'j'
            time+=chefs[i]*j;

            //increase j
            j++;
        }

        //if the amount of paratha made is sufficient return true
        if(count>=parathas){
            return 1;
        }
    }
    return 0;
}

int solve(vector<int> chefs,int parathas){

    //lowest time
    int low=0;

    //highest time
    int high=100000000;

    //to store the time
    int answer=0;

    //iterate till they cross each other
    while(low<=high){

        //calculate the middle value
        int mid=low+((high-low)/2);

        //check if parathas can be made in that middle value time
        if(isSufficientParathas(chefs,parathas,mid)){

            //if yes store as possible answer
            answer=mid;

            //check if it is possible for lesser time
            high=mid-1;
        }
        
        //if the parathas cannot be made in that middle value time
        else{

            //check for higher time
            low=mid+1;
        }
    }
    return answer;
}

int main() {
    int p, l;
    cin >> p;  // Number of pratas required
    cin >> l;  // Number of cooks
    vector<int> chefs(l);
    for (int i = 0; i < l; i++) {
        cin >> chefs[i];  // Read the rank of each cook
    }

    // Call the solve function to get the minimum time and print the result
    cout << solve(chefs, p) << endl;

    return 0;
}