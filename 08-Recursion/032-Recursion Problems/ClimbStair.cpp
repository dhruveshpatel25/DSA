/*Count Ways To Reach The N-th Stairs
You have been given a number of stairs. Initially, you are at the 0th stair, and you need to reach the Nth stair.
Each time, you can climb either one step or two steps.
You are supposed to return the number of distinct ways you can climb from the 0th step to the Nth step.
https://www.naukri.com/code360/problems/count-ways-to-reach-nth-stairs_798650?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar*/
#include<iostream>
using namespace std;

int climbstair(int num){

    //if we reached the negative step return 0
    if(num<0){
        return 0;
    }

    //if we reached the ground level return 1
    if(num==0){
        return 1;
    }

    //recursivly call for n-1step or n-2step
    return climbstair(num-1)+climbstair(num-2);
}

int main(){
    int num;
    cout<<"Enter the no.of stairs: ";
    cin>>num;
    int result=climbstair(num);
    cout<<"No. of ways are: "<<result;
}