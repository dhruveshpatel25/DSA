/*Count Primes
Given an integer n, return the number of prime numbers that are strictly less than n.

Example 1:
Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

Example 2:
Input: n = 0
Output: 0

Example 3:
Input: n = 1
Output: 0
https://leetcode.com/problems/count-primes/description/*/
#include<iostream>
#include<vector>
using namespace std;

int CountOfPrime(int n){
    int count=0;
    vector<bool> prime(n+1,true);
    prime[0]=prime[1]=false;

    //iterate for all the numbers from 2-n
    for(int i=2;i<n;i++){

        //check whether that current value is prime or not
        if(prime[i]){

            //if prime increase the count
            count++;

            //now check for every multiple of that number(i.e 'i' will be 2,3,7,etc)
            for(int j=2*i; j<n; j=j+i){

                //convert all the multiple to false (so they need not to be checked again as they won't be prime)
                prime[j]=0;
            }
        }
    }
    return count;
}

int main(){
    int number;
    cout<<"Enter the number ";
    cin>>number;
    cout<<CountOfPrime(number);
}