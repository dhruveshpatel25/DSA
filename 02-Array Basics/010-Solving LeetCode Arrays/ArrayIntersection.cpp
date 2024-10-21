#include<iostream>
#include<climits>
using namespace std;

int Intersection(int arr1[],int arr2[],int size1, int size2){
    for(int i=0; i<size1;i++){
        int element=arr1[i];
        for(int j=0;j<size2;j++){
            if(element==arr2[j]){
                cout<<element<<" ";
                arr2[j]=INT_MIN;
                break;
            }
        }
    }
}
int main(){
    int arr1[6]={1,2,2,2,3,4};
    int arr2[4]={2,2,3,3};
    Intersection(arr1,arr2,6,4);
}