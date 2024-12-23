/* Square Root of a number
You are given a positive integer ‘n’.
Your task is to find and return its square root. If ‘n’ is not a perfect square, then return the floor value of sqrt(n).

Example:
Input: ‘n’ = 7
Output: 2
Explanation:
The square root of the number 7 lies between 2 and 3, so the floor value is 2.
*/
#include<iostream>
using namespace std;

int BinarySearch(int key){

    //left pointer
    int start=0;

    //right pointer at the key element
    int end = key;

    //to store the value
    int ans=-1;

    //iterate till the left and right pointer dont cross
    while(start<=end){

        //get the middle value
        int mid=start+((end-start)/2);

        //check if square of middle element greater than the key element
        if(mid*mid>key){

            //move the right pointer left of the middle element
            end=mid-1;
        }
        //if the square of middle element same as key
        else if(mid*mid==key){

            //return as square root
            return mid;
        }
        //if the square of middle element smaller than the key element
        else{

            //store as potential answer
            ans=mid;

            //move the left pointer to the right of middle element
            start=mid+1;
        }
    }
    return ans;
}

int main() {
    int num = 9;
    cout << "Square root of " << num << " is: " << BinarySearch(num) << endl;
    return 0;
}