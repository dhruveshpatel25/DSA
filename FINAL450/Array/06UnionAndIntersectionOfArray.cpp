#include<bits/stdc++.h>
using namespace std;

int Union(vector<int> &arr1,int size1,vector<int> &arr2,int size2){
    int count=0;
    unordered_map<int,bool> elements_map;
    for(int i=0;i<size1;i++){
        elements_map[arr1[i]]=true;
    }

    for(int i=0;i<size2;i++){
        elements_map[arr2[i]]=true;
    }

    for(auto i=elements_map.begin();i!=elements_map.end();i++){
        if(i->second==true){
            count++;
        }
    }
    return count;
}

int Intersection(vector<int> &arr1,int size1,vector<int> &arr2,int size2){
    int count=0;
    unordered_map<int,bool> elements_map;
    for(int i=0;i<size1;i++){
        elements_map[arr1[i]]=true;
    }

    for(int i=0;i<size2;i++){
        if (elements_map.find(arr2[i]) != elements_map.end() && elements_map[arr2[i]]){
            elements_map[arr2[i]]=false;
        }
    }

    for(auto i=elements_map.begin();i!=elements_map.end();i++){
        if(i->second==false){
            count++;
        }
    }
    return count;
}
int main(){
    int size1;
    cout<<"Enter the size of first array: ";
    cin>>size1;
    vector<int> arr1(size1);
    cout<<"Enter the elements for first array: ";
    for(int i=0;i<size1;i++){
        cin>>arr1[i];
    }
    int size2;
    cout<<"Enter the size of second array: ";
    cin>>size2;
    vector<int> arr2(size2);
    cout<<"Enter the elements for second array: ";
    for(int i=0;i<size2;i++){
        cin>>arr2[i];
    }
    cout<<"The no.of of Union elements of 2 array are: "<<Union(arr1,size1,arr2,size2)<<endl;
    cout<<"The no.of of Intersection elements of 2 array are: "<<Intersection(arr1,size1,arr2,size2)<<endl;
}