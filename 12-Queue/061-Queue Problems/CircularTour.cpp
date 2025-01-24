/*Gas Station
There are some gas stations along a circular route. You are given two integer arrays gas[] denoted as the amount of gas present at each station and cost[] denoted as the cost of travelling to the next station. You have a car with an unlimited gas tank. You begin the journey with an empty tank from one of the gas stations. Return the index of the starting gas station if it's possible to travel around the circuit without running out of gas at any station in a clockwise direction. If there is no such starting station exists, return -1.
Note: If a solution exists, it is guaranteed to be unique.

Examples:

Input: gas[] = [4, 5, 7, 4], cost[]= [6, 6, 3, 5]
Output: 2
Explanation: It is possible to travel around the circuit from station at index 2.
Amount of gas at station 2 is (7 - 3) 4.
Amount of gas at station 3 is (4 + 4 - 5) 3.
Amount of gas at station 0 is (3 + 4 - 6) 1.
Amount of gas at station 1 is (1 + 5 - 6) 0.

Input: gas[] = [1, 2, 3, 4, 5], cost[] = [3, 4, 5, 1, 2]
Output: 3
Explanation: It is possible to travel around the circuit from station at index 3.
Amount of gas at station 3 is (4 - 1) 3.
Amount of gas at station 4 is (3 + 5 - 2) 6.
Amount of gas at station 0 is (6 + 1 - 3) 4.
Amount of gas at station 1 is (4 + 2 - 4) 2.
Amount of gas at station 2 is (2 + 4 - 5) 1.

Input: gas[] = [3, 9], cost[] = [7, 6]
Output: -1
Explanation: There is no gas station to start with such that you can complete the circuit.
https://www.geeksforgeeks.org/problems/circular-tour-1587115620/1*/
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

int tour(petrolPump p[],int number){
    int balance=0;
    int deficient=0;
    int start=0;

    //iterate the array
    for(int i=0;i<number;i++){

        //check whether the current petrol remaining is able to cover the distance
        balance+=p[i].petrol-p[i].distance;

        //if not
        if(balance<0){

            //add to deficient
            deficient=deficient+balance;

            //save start point as 1 element ahead
            start=i+1;

            //make balance 0
            balance=0;
        }
    }

    //if the sum of balance and deficient is 0 or above then return the start point
    if(balance+deficient>=0){
        return start;
    }else{
        return -1;
    }
}

int main() {
    petrolPump pumps[] = {
        {4, 6}, 
        {6, 5}, 
        {7, 3},
        {4, 5}  
    };

    int number = sizeof(pumps) / sizeof(pumps[0]);

    int startPoint = tour(pumps, number);

    if (startPoint == -1) {
        cout << "No solution exists";
    } else {
        cout << "Start Point: " << startPoint;
    }

    return 0;
}
