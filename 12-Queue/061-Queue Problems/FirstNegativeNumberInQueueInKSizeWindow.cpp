#include<iostream>
#include<queue>
#include<stack>
using namespace std;

vector<int> firstNegative(vector<int> arr,int size,int windowsize){
    deque<int> deq;
    vector<int> ans;

    //pushing the first window size elements from array to doubly ended queue
    for(int i=0;i<windowsize;i++){

        //pushing only the negative number index
        if(arr[i]<0){
            deq.push_back(i);
        }
    }

    //first negative number of the window
    if(deq.size()>0){
        ans.push_back(arr[deq.front()]);
    }
    
    //if there exist no negative number in that window
    else{
        ans.push_back(0);
    }

    //now processing the next window
    for(int i=windowsize;i<size;i++){

        //remove the first element of the window
        if(!deq.empty() && i-deq.front()>=windowsize){
            deq.pop_front();
        }

        //adding the next element in the window
        if(arr[i]<0){
            deq.push_back(i);
        }

        //first negative number of that window
        if(deq.size()>0){
            ans.push_back(arr[deq.front()]);
        }

        //if there is no negative number in that window
        else{
            ans.push_back(0);
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {12, -1, -7, 8, -15, 30, 16, 28};
    int size = arr.size();
    int windowsize = 3;

    vector<int> result = firstNegative(arr, size, windowsize);

    cout << "First negative elements in each window: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}