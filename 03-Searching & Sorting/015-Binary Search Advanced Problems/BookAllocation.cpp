/*Allocate Books
Given an array ‘arr’ of integer numbers, ‘arr[i]’ represents the number of pages in the ‘i-th’ book.
There are ‘m’ number of students, and the task is to allocate all the books to the students.
Allocate books in such a way that:
1. Each student gets at least one book.
2. Each book should be allocated to only one student.
3. Book allocation should be in a contiguous manner.
You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum.
If the allocation of books is not possible, return -1.

Example:
Input: ‘n’ = 4 ‘m’ = 2 
‘arr’ = [12, 34, 67, 90]
Output: 113
Explanation: All possible ways to allocate the ‘4’ books to '2' students are:
12 | 34, 67, 90 - the sum of all the pages of books allocated to student 1 is ‘12’, and student two is ‘34+ 67+ 90 = 191’, so the maximum is ‘max(12, 191)= 191’.
12, 34 | 67, 90 - the sum of all the pages of books allocated to student 1 is ‘12+ 34 = 46’, and student two is ‘67+ 90 = 157’, so the maximum is ‘max(46, 157)= 157’.
12, 34, 67 | 90 - the sum of all the pages of books allocated to student 1 is ‘12+ 34 +67 = 113’, and student two is ‘90’, so the maximum is ‘max(113, 90)= 113’.
We are getting the minimum in the last case.
Hence answer is ‘113’.
https://www.naukri.com/code360/problems/allocate-books_1090540*/
#include<iostream>
using namespace std;

bool Possible(int arr[],int size,int student,int mid){

    //start with student1
    int StudentCount=1;

    //to calculate the pages
    int PageSum=0;

    //iterate all the books
    for(int i=0; i<size ; i++){

        //check whether the pages are less than the maximum pages 
        if(arr[i]+PageSum <= mid){

            //if yes add pages
            PageSum+=arr[i];
        }
        
        //if no
        else{

            //now go with other students
            StudentCount++;

            //check whether the studentcount is less than the student and the pages are less than the maximum page
            if(StudentCount>student || arr[i]> mid ){

                //if no then return false
                return false;
            }
            
            //if yes
            else{

                //add pages for that paticular student
                PageSum=arr[i];
            }
        }
    }
    return true;
}

int Allocate(int arr[],int size,int student){

    //start pointer
    int start=0;

    //to store maximum pages
    int sum=0;

    //iterate complete array
    for(int i=0; i<size; i++){

        //store the sum of pages
        sum= sum+arr[i];
    }

    //to store the value 
    int ans=0;

    //end pointer
    int end=sum;

    //iterate till they cross each other
    while(start<=end){

        //get middle value
        int mid = start+((end-start)/2);

        //check if it is possible to allocate books
        if(Possible(arr,size,student,mid)){

            //store the middle value as possible solution
            ans=mid;

            //now check whether it is possible for smaller value of pages
            end=mid-1;
        }
        
        //check for higher value
        else{
            start=mid+1;
        }
    }
    return ans;
}

int main(){
    int arr[5]={25,46,28,49,24};
    int students=4;
    cout<<Allocate(arr,5,4);
}