#include<iostream>
using namespace std;

bool FindUniqueOccurence(int arr[],int size){
    int count[100]={0};
    for(int i=0;i<size;i++){
        count[arr[i]]++;
    }
    int freq[100]={0};
    for(int i=0;i<100;i++){
        if(count[i]>0){
            if(freq[count[i]]>0){
                return false;
            }
            freq[count[i]]=1;
        }
    }
    return true;
}
int main(){
    int arr[6]={1,2,2,3,3,3};
    bool result=FindUniqueOccurence(arr,6);
    if(result){
        cout<<"True";
    }else{
        cout<<"False";
    }
}