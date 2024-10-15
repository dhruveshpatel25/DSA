#include<iostream>
#include<queue>
using namespace std;

int sumOfMaxandMin(int *arr,int size,int windowsize){
    deque<int> maxi(windowsize);
    deque<int> mini(windowsize);

    for(int i=0;i<windowsize;i++){
        while(!maxi.empty() && arr[maxi.back()]<=arr[i]){
            maxi.pop_back();
        }

        while(!mini.empty() && arr[mini.back()]>=arr[i]){
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);
    }

    int ans=0;
    ans += arr[maxi.front()] + arr[mini.front()];

    for(int i=windowsize;i<size;i++){
        while(!maxi.empty() && i-maxi.front()>=windowsize){
            maxi.pop_front();
        }

        while(!mini.empty() && i-mini.front()>=windowsize){
            mini.pop_front();
        }

        while(!maxi.empty() && arr[maxi.back()]<=arr[i]){
            maxi.pop_back();
        }

        while(!mini.empty() && arr[mini.back()]>=arr[i]){
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);

        ans+= arr[maxi.front()]+arr[mini.front()];
    } 
    return ans;
}

int main() {
    int arr[7] = {2, 5, -1, 7, -3, -1, -2};
    int k = 4;
    cout << sumOfMaxandMin(arr, 7, k) << endl;
    return 0;
}