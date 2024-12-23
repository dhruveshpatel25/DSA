#include<iostream>
using namespace std;
int LastOccurrence(int arr[],int size, int key){

    //left pointer
    int start=0;

    //right pointer
    int end=size-1;

    //to store the value
    int ans=-1;

    //iterate till the left and right pointer dont cross
    while(start<=end){

        //get the middle value
        int mid= start+((end-start)/2);

        //if the middle value is the key element
        if(key==arr[mid]){

            //store that answer
            ans=mid;

            //move the left pointer to check for more value
            start=mid+1;
        }
        //if the key element is greater than the middle element
        else if(key>arr[mid]){

            //move the left pointer to the right of middle element
            start=mid+1;
        }
        //if the key element is smaller than the middle element
        else{

            //move the right pointer to the left of middle element
            end=mid-1;
        }
    }
    return ans;
}

int FirstOccurrence(int arr[],int size, int key){

    //left pointer
    int start=0;

    //right pointer
    int end=size-1;

    //to store the value
    int ans=-1;

    //iterate till the left and right pointer dont cross
    while(start<=end){

        //get the middle value
        int mid= start+((end-start)/2);

        //if the middle value is the key element
        if(key==arr[mid]){

            //store that answer
            ans=mid;

            //move the right pointer to check for more values
            end=mid-1;
        }
        //if the key element is greater than the middle element
        else if(key>arr[mid]){

            //move the left pointer to the right of middle element
            start=mid+1;
        }
        //if the key element is smaller than the middle element
        else{

            //move the right pointer to the left of middle element
            end=mid-1;
        }
    }
    return ans;
}
int main(){
    int arr[9]={1,1,2,2,2,2,4,4,4};
    int result1=FirstOccurrence(arr,9,2);
    int result2=LastOccurrence(arr,9,2);
    int total;
    
    //calculate the difference
    total=(result2-result1)+1;
    cout<<total;
}