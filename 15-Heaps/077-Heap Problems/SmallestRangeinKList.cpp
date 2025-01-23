/*Smallest Range From K Sorted List
You are given ‘K’ lists containing non-negative integers. Each list has a size ‘N’ and is sorted in non-decreasing order. You need to find the minimum length of a range such that at least one element of each list must be included in that range.

For example :

If we have 3 lists as [1, 10, 11], [2, 3, 20], [5, 6, 12] then the [1, 5] is the range that includes 1 from the first list, 2,3 from the second list, and 5 from the third list i.e, this range contains at least one element from each list.
https://www.naukri.com/code360/problems/smallest-range-from-k-sorted-list_1069356*/
#include <bits/stdc++.h> 
using namespace std;

class Node{
    public:
    int data;
    int row;
    int col;

    Node(int data,int row,int col){
        this->data=data;
        this->row=row;
        this->col=col;
    }
};

class compare{
    public:
    bool operator()(Node* a,Node* b){
        return a->data>b->data;
    }
};

int KSorted(vector<vector<int>> &arr,int k,int size){
    int mini=INT_MAX;
    int maxi=INT_MIN;

    //priority queue in ascending order
    priority_queue<Node*,vector<Node*>,compare> pq;
    for(int i=0;i<k;i++){
        int element=arr[i][0];

        //save the maxi and mini value of all the k list
        mini=min(mini,element);
        maxi=max(maxi,element);
        pq.push(new Node(element,i,0));
    }

    //now we have all the maxi and min values of the k list
    int start=mini;
    int end=maxi;

    while(pq.size()>0){
        Node* temp=pq.top();
        pq.pop();

        //now we start with the smallest value in priority queue
        mini=temp->data;

        //we check if the range is smaller or not
        if(maxi-mini<end-start){
            start=mini;
            end=maxi;
        }

        //now we iterate to the next value in the list
        if(temp->col+1<size){
            maxi=max(maxi,arr[temp->row][temp->col+1]);
            pq.push(new Node(arr[temp->row][temp->col+1],temp->row,temp->col+1));
        }else{
            break;
        }
    }
    return (end-start+1);
}

int main(){
    vector<vector<int>> arr = {
        {1, 3, 5, 7},
        {2, 4, 6, 8},
        {0, 9, 10, 11}
    };
    int k = 3;
    int size = 4;
    cout << "The size of the smallest possible subarray containing elements from all rows is: "<< KSorted(arr, k, size) << endl;
    return 0;
}