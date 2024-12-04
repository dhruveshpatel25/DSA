#include<iostream>
#include <climits>
using namespace std;

int MAX(int num[],int n){

    //INT_MIN means the minimum integer value
    int max= INT_MIN;
    for(int i=0;i<n;i++){
        if(num[i]>max){

            //if you get maximum then save in max
            max=num[i];
        }
    }
    return max;
}

int MIN(int num[],int n){

    //INT_MAX means the maximum integer value
    int min=INT_MAX;
    for(int i=0;i<n;i++){
        
        //if you get minimum then save in min
        if(num[i]<min){
            min=num[i];
        }
    }
    return min;
}

int main(){
    int size;
    cout<<"Enter the size for array: ";
    cin>>size;
    int num[1000];
    for(int i=0;i<size;i++){
        cin>>num[i];
    }
    cout<<"The Maximum Value is: "<<MAX(num,size)<<endl;
    cout<<"The Minimum Value is: "<<MIN(num,size)<<endl;
}