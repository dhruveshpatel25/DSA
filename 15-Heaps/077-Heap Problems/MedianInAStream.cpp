/*Median in a stream
Given that integers are read from a data stream. Your task is to find the median of the elements read so far.

Median is the middle value in an ordered integer list. If the size of the list is even there is no middle value. So the median is the floor of the average of the two middle values.
https://www.naukri.com/code360/problems/median-in-a-stream_975268*/
#include <bits/stdc++.h> 
using namespace std;


//checking for the size of array on both side of median
int signum(int num1, int num2){

    //if both the side has same no.of array
    if(num1==num2){
        return 0;

    // if left array is greater than right
    }else if(num1>num2){
        return 1;
    }else{ // if right array is greater than left
        return -1;
    }
}

void callMedian(int element,priority_queue<int> &maxHeap,priority_queue<int, vector<int>, greater<int> > &minHeap,int &median){

    //checking in signum function
    switch(signum(maxHeap.size(),minHeap.size())){

        //when both the side has same length
        case 0: if(element>median){

                    //push in the right array 
                    minHeap.push(element);

                    //the top of right array becomes the median as it pushes the value to leftside and making it an odd array
                    median=minHeap.top();
                }else{

                    //pushing the element in the left array
                    maxHeap.push(element);

                    //the top of right array becomes the median as it pushes the value to the rightside and making it an odd array
                    median=maxHeap.top();
                }
                break;

        //when left array has a greater length
        case 1: if(element>median){

                    //pushing the element in the right array
                    minHeap.push(element);

                    //the average of both the top as the it pushes the value to the rightside and making it an even array
                    median=(minHeap.top()+maxHeap.top())/2;
                }else{

                    //pushing the top value of left array to right array as the element will push the element out of length
                    minHeap.push(maxHeap.top());

                    //empting the space
                    maxHeap.pop();

                    //pushing the new element
                    maxHeap.push(element);

                    //the average of both the top as the it pushes the value to the rightside and making it an even array
                    median=(minHeap.top()+maxHeap.top())/2;
                }
                break;

        //when right array has a greater length
        case -1: if(element>median){

                    //pushing the top value of right array to left array as the element will push the element out of length
                    maxHeap.push(minHeap.top());

                    //empting the space
                    minHeap.pop();

                    //pushing the new element
                    minHeap.push(element);

                    //the average of both the top as the it pushes the value to the leftside and making it an even array
                    median=(minHeap.top()+maxHeap.top())/2;
                }else{
                    //pushing the element in the left array
                    maxHeap.push(element);

                    //the average of both the top as the it pushes the value to the leftside and making it an even array
                    median=(minHeap.top()+maxHeap.top())/2;
                }
                break;
    }
}
vector<int> findMedian(vector<int> &arr,int size){
    vector<int> ans;
    //containing value smaller than median in descending order
    priority_queue<int> maxHeap;

    //containing value greater than median in ascending order
    priority_queue<int, vector<int>, greater<int> > minHeap;
    int median=0;
    for(int i=0;i<size;i++){
        callMedian(arr[i],maxHeap,minHeap,median);
        ans.push_back(median);
    }
    return ans;
}

int main() {
    // Input data stream
    vector<int> arr = {5, 15, 10, 20, 3};
    int size = arr.size();

    // Find medians for the given data stream
    vector<int> medians = findMedian(arr, size);

    // Print the medians as they are calculated
    cout << "Medians in the stream: ";
    for (int median : medians) {
        cout << median << " ";
    }
    cout << endl;

    return 0;
}
