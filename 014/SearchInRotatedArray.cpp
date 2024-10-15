#include<iostream>
using namespace std;

int Pivot(int arr[], int size){
    int start=0;
    int end= size-1;
    while(start<=end){
        int mid= start+((end-start)/2);
        if(arr[mid]>arr[0]){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        
    }
    return start;
}

int BinarySearch(int arr[],int start, int end ,int key){

    int mid=start+(end-start)/2;
    while(start<=end){
        if(key==arr[mid]){
            return mid;
        }
        if(key>arr[mid]){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        mid=start+(end-start)/2;
    }
    return -1;
}

int FindPosition(int arr[],int size,int k){
    int pivot=Pivot(arr,size);
    if (k >= arr[pivot] && k<=arr[size-1]){
        return BinarySearch(arr,pivot,size-1,k);
    }
    else{
        return BinarySearch(arr,0,pivot-1,k);
    }
}
int main(){
    int arr[] = {4, 5, 6, 7, 8, 9, 1, 2, 3};
    int key = 2;
    int size = sizeof(arr) / sizeof(arr[0]);

    int position = FindPosition(arr, size,key);

    if(position != -1){
        cout << "Element found at index " << position << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}