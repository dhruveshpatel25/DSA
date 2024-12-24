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

    //to mark whether prime or not
    vector<bool> isPrime(limits+1,true);

    //marking 0&1 as non-prime
    isPrime[0]=isPrime[1]=false;

    //to store all the primes
    vector<int> primes;

    //iterate for all the numbers from 2-limits
    for(int i=2;i<=limits;i++){

        //check whether that current value is prime or not
        if(isPrime[i]){

            //if prime push to new array
            primes.push_back(i);

            //mark all the non-prime false(we did i*i beacause it is optimise way)
            for(int j=i*i; j<=limits; j=j+i){
                isPrime[j]=0;
            }
        }
    }
    return primes;
}

int segmentedSieve(int left, int right){

    //find the limit(we did sqrt because for any non prime number there would be one prime in that range)
    int limit=sqrt(right);

    //get the prime values 
    vector<int> prime=simpleSieve(limit);

    //mark all the numbers in the range of left to right true(meaning all are prime now)
    vector<bool> secondIsPrime(right-left+1,true);
    for(int primes:prime){

        //prime*prime is done as any number below prime*prime will be marked false so it makes as a start
        //(left+primes-1)/primes*primes is done to calculate the correct stating position in that range
        int start=max(primes*primes,(left+primes-1)/primes*primes);

        //mark all the multiple of start to non-prime
        for(int j=start;j<=right;j=j+primes){
            secondIsPrime[j-left]=0;
        }
    }

    //if the range contains 1 then mark that as non-prime
    if(left==1){
        secondIsPrime[0]=false;
    }

    //counter
    int count=0;

    //iterate the complete range
    for(int i=0;i<=right-left;i++){

        //check whether prime or not
        if(secondIsPrime[i]){

            //if prime increase the counter
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