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
    int StudentCount=1;
    int PageSum=0;
    for(int i=0; i<size ; i++){
        if(arr[i]+PageSum <= mid){
            PageSum+=arr[i];
        }else{
            StudentCount++;
            if(StudentCount>student || arr[i]> mid ){
                return false;
            }else{
                PageSum=arr[i];
            }
        }
    }
    return true;
}

int Allocate(int arr[],int size,int student){
    int start=0;
    int sum=0;
    for(int i=0; i<size; i++){
        sum= sum+arr[i];
    }
    int ans=0;
    int end=sum;
    while(start<=end){
        int mid = start+((end-start)/2);
        if(Possible(arr,size,student,mid)){
            ans=mid;
            end=mid-1;
        }else{
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