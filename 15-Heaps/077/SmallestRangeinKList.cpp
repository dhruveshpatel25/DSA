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
    priority_queue<Node*,vector<Node*>,compare> pq;
    for(int i=0;i<k;i++){
        int element=arr[i][0];
        mini=min(mini,element);
        maxi=max(maxi,element);
        pq.push(new Node(element,i,0));
    }

    int start=mini;
    int end=maxi;

    while(pq.size()>0){
        Node* temp=pq.top();
        pq.pop();
        mini=temp->data;
        if(maxi-mini<end-start){
            start=mini;
            end=maxi;
        }

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