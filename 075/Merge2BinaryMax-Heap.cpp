#include<iostream>
#include<vector>
using namespace std;

void heapify(vector<int> &arr,int size,int index){
    int largest=index;
    int leftindex=2*index+1;
    int rightindex=2*index+2;

    if(leftindex<=size && arr[largest]<arr[leftindex]){
        largest=leftindex;
    }
    if(rightindex<=size && arr[largest]<arr[rightindex]){
        largest=rightindex;
    }

    if(largest!=index){
        swap(arr[largest],arr[index]);
        heapify(arr,size,largest);
    }
}

vector<int> merge2BinaryMaxHeap(vector<int> &arr1,vector<int> &arr2,int size1,int size2){
    vector<int> ans;

    for(auto i:arr1){
        ans.push_back(i);
    }
    for(auto i:arr2){
        ans.push_back(i);
    }

    int size3=ans.size();
    for(int i=size3/2-1;i>=0;i--){
        heapify(ans,size3-1,i);
    }
    return ans;
}

int main() {
    vector<int> arr1 = {10, 5, 6, 2};
    vector<int> arr2 = {12, 7, 9};
    int size1=arr1.size();
    int size2=arr2.size();

    vector<int> mergedHeap = merge2BinaryMaxHeap(arr1, arr2, size1, size2);

    cout << "Merged Max Heap: ";
    for (int i = 0; i < mergedHeap.size(); ++i) {
        cout << mergedHeap[i] << " ";
    }
    cout << endl;

    return 0;
}