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
#include<cmath>
using namespace std;

vector<int> simpleSieve(int limits){
    vector<bool> isPrime(limits+1,true);
    isPrime[0]=isPrime[1]=false;
    vector<int> primes;
    for(int i=2;i<=limits;i++){
        if(isPrime[i]){
            primes.push_back(i);
            for(int j=i*i; j<=limits; j=j+i){
                isPrime[j]=0;
            }
        }
    }
    return primes;
}

int segmentedSieve(int left, int right){
    int limit=sqrt(right);
    vector<int> prime=simpleSieve(limit);
    vector<bool> secondIsPrime(right-left+1,true);
    for(int primes:prime){
        int start=max(primes*primes,(left+primes-1)/primes*primes);
        for(int j=start;j<=right;j=j+primes){
            secondIsPrime[j-left]=0;
        }
    }
    if(left==1){
        secondIsPrime[0]=false;
    }
    int count=0;
    for(int i=0;i<=right-left;i++){
        if(secondIsPrime[i]){
            count++;
        }
    }
    return count;
}

int main(){
    int left,right;
    cout<<"Enter the left value of array: ";
    cin>>left;
    cout<<"Enter the right value of the array: ";
    cin>>right;
    cout<<"The no. of primes are: "<<segmentedSieve(left,right);
}