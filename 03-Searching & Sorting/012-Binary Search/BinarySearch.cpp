#include<iostream>
using namespace std;

int BinarySearch(int arr[],int size,int key){

    //left pointer
    int start=0;

    //right pointer
    int end=size-1;

    //get the middle value
    int mid=start+(end-start)/2;

    //iterate till the left and right pointer dont cross
    while(start<=end){

        //if the middle value is the key element
        if(key==arr[mid]){

            //return the value
            return mid;
        }

        //if the key element is greater than the middle element
        if(key>arr[mid]){

            //move the left pointer to the right of middle element
            start=mid+1;
        }

        //if the key element is smaller than the middle element
        else{

            //move the right pointer to the left of middle element
            end=mid-1;
        }

        //update the middle value
        mid=start+(end-start)/2;
    }
    return -1;
}
int main(){
    int arr[5]={1,2,3,4,5};
    int result=BinarySearch(arr,5,5);
    if (result != -1) {
        cout << "The key is found at index " << result;
    } else {
        cout << "The key does not exist";
    }
}