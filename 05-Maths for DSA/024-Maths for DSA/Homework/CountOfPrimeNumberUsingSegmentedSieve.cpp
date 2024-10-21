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