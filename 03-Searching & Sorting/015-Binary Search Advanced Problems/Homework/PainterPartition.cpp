/*Painter's Partition Problem
Given an array/list of length ‘n’, where the array/list represents the boards and each element of the given array/list represents the length of each board. Some ‘k’ numbers of painters are available to paint these boards. Consider that each unit of a board takes 1 unit of time to paint.
You are supposed to return the area of the minimum time to get this job done of painting all the ‘n’ boards under a constraint that any painter will only paint the continuous sections of boards.

Example :
Input: arr = [2, 1, 5, 6, 2, 3], k = 2
Output: 11
Explanation:
First painter can paint boards 1 to 3 in 8 units of time and the second painter can paint boards 4-6 in 11 units of time. Thus both painters will paint all the boards in max(8,11) = 11 units of time. It can be shown that all the boards can't be painted in less than 11 units of time.
https://www.naukri.com/code360/problems/painter-s-partition-problem_1089557*/
#include<iostream>
using namespace std;

bool Possible(int arr[],int size, int painter,int mid){

    //count for painter 1
    int PainterCount=1;

    //to store the space taken
    int TimeSum=0;

    //iterate to check the space
    for(int i=0;i<size;i++){

        //if the space taken is less than the maximum space
        if(TimeSum+arr[i]<=mid){

            //add it to space
            TimeSum+=arr[i];
        }
        
        //if not give space to next painter
        else{
            PainterCount++;

            //check whether thare is painter left and also check whether space given is less than maximum
            if(PainterCount>painter || arr[i]>mid){
                return false;
            }
            
            //if there is painter left and space is left
            else{

                //add space to new painter
                TimeSum=arr[i];
            }
        }
    }
    return true;
}

int Partition(int arr[],int size,int painter){

    //lowest space
    int start=0;

    //total sum space
    int sum=0;

    //iterate the whole array
    for(int i=0; i<size; i++){

        //sum all the spaces
        sum+=arr[i];
    }

    //highest space
    int end=sum;

    //to store the space to be given
    int ans=0;

    //iterate till they cross each other
    while(start<=end){

        //get the middle value
        int mid=start+((end-start)/2);

        //check whether the space is sufficient
        if(Possible(arr,size,painter,mid)){

            //if sufficient they store the middle value as possible answer
            ans=mid;

            //check if we can iterate for more smaller space
            end=mid-1;
        }

        //if space is not sufficient check for greater space
        else{
            start=mid+1;
        }
    } 
    return ans;   
}
int main(){
    int arr[6]={2,1,5,6,2,3};
    cout<<Partition(arr,6,2);
}