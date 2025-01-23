/*/* Nth Fibonacci Number
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
#include<iostream>
using namespace std;

int fibonacci(int place){

    //if the place called is 0
    if(place==0){
        return 0;
    }

    //if the place called is 1
    if(place==1){
        return 1;
    }

    //recursivly call for n-1 and n-2,sum it and store
    int ans= fibonacci(place-1)+fibonacci(place-2);
    return ans;
}

int main(){
    int place;
    cout<<"Enter the position: ";
    cin>>place;
    int result=fibonacci(place);
    cout<<"The value is "<<result;
    return 0;
}