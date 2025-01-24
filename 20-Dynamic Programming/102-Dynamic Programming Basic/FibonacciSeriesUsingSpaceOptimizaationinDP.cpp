/* Nth Fibonacci Number
The n-th term of Fibonacci series F(n), where F(n) is a function, is calculated using the following formula -
F(n) = F(n - 1) + F(n - 2), 
Where, F(1) = 1, F(2) = 1
Provided 'n' you have to find out the n-th Fibonacci Number. Handle edges cases like when 'n' = 1 or 'n' = 2 by using conditionals like if else and return what's expected.
"Indexing is start from 1"

Example :
Input: 6
Output: 8
Explanation: The number is ‘6’ so we have to find the “6th” Fibonacci number.
So by using the given formula of the Fibonacci series, we get the series:    
[ 1, 1, 2, 3, 5, 8, 13, 21]
So the “6th” element is “8” hence we get the output.
https://www.naukri.com/code360/problems/nth-fibonacci-number_74156*/
#include<bits/stdc++.h>
using namespace std;

int fibonacci(int n){

    //save the prev1 as 1
    int prev1=1;

    //save the prev2 as 0
    int prev2=0;

    //if n is 0
    if(n==0){
        return prev2;
    }

    //iterate for n=2
    for(int i=2;i<=n;i++){

        //sum the 2 previous value
        int curr=prev1+prev2;

        //shift the prev2 to prev1
        prev2=prev1;

        //shift the prev1 to curr
        prev1=curr;
    }

    return prev1;
}

int main(){
    int place;
    cin>>place;
    int result=fibonacci(place);
    cout<<"The value is "<<result;
    return 0;
}