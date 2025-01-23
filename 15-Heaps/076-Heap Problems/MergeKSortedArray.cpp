/*Merge K Sorted Arrays
You have been given ‘K’ different arrays/lists, which are sorted individually (in ascending order). You need to merge all the given arrays/list such that the output array/list should be sorted in ascending order.
https://www.naukri.com/code360/problems/merge-k-sorted-arrays_975379*/
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

vector<int> mergeKSorted(vector<vector<int>> &karray,int k){

    //priority queue in ascending order
    priority_queue<Node*, vector<Node*>, compare> pq;

    //push the first elements of all array
    for(int i=0;i<k;i++){

        //data,row,column
        Node *temp = new Node(karray[i][0],i,0);
        pq.push(temp);
    }

    vector<int> ans;


    while(pq.size()>=1){
        Node* temp= pq.top();

        //smallest value from the priority queue
        ans.push_back(temp->data);
        pq.pop();

        //retrieving the row from the value
        int i=temp->row;

        //retrieving the column from the value
        int j=temp->col;

        //increasing the column value and checking if it is less than the array size of that particular array
        if(j+1<karray[i].size()){

            //if true then push that value in priority queue
            Node* next=new Node(karray[i][j+1],i,j+1);
            pq.push(next);
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> karray = {
        {1, 3, 5, 7},
        {2, 4, 6, 8},
        {0, 9, 10, 11},
        {12,13,14,15}
    };
    int k = karray.size();

    vector<int> result = mergeKSorted(karray, k);

    cout << "Merged Sorted Array: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}