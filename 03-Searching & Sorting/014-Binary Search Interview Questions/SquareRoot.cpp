#include<iostream>
using namespace std;

int BinarySearch(int key){
    int start=0;
    int end = key;
    int ans=-1;
    while(start<=end){
        int mid=start+((end-start)/2);
        if(mid*mid>key){
            end=mid-1;
        }else if(mid*mid==key){
            return mid;
        }else{
            ans=mid;
            start=mid+1;
        }
    }
    return ans;
}

int main() {
    int num = 9;
    cout << "Square root of " << num << " is: " << BinarySearch(num) << endl;
    return 0;
}