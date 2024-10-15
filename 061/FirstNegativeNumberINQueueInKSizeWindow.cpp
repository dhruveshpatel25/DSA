#include<iostream>
#include<queue>
#include<stack>
using namespace std;

vector<int> firstNegative(vector<int> arr,int size,int windowsize){
    deque<int> deq;
    vector<int> ans;

    for(int i=0;i<windowsize;i++){
        if(arr[i]<0){
            deq.push_back(i);
        }
    }

    if(deq.size()>0){
        ans.push_back(arr[deq.front()]);
    }else{
        ans.push_back(0);
    }

    for(int i=windowsize;i<size;i++){
        if(!deq.empty() && i-deq.front()>=windowsize){
            deq.pop_front();
        }

        if(arr[i]<0){
            deq.push_back(i);
        }

        if(deq.size()>0){
            ans.push_back(arr[deq.front()]);
        }else{
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