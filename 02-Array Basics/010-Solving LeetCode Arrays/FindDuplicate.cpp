/*Duplicate In Array
You are given an array ‘ARR’ of size ‘N’ containing each number between 1 and ‘N’ - 1 at least once. There is a single integer value that is present in the array twice. Your task is to find the duplicate integer value present in the array.

For example:

Consider ARR = [1, 2, 3, 4, 4], the duplicate integer value present in the array is 4. Hence, the answer is 4 in this case.
https://www.naukri.com/code360/problems/duplicate-in-array_893397?source=youtube&campaign=love_babbar_codestudio1&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio1*/
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

void findDuplicates(const vector<int>& arr) {
    unordered_set<int> seen;
    bool hasDuplicates = false;

    for (int num : arr) {

        //check in seen array if it present or not
        if (seen.find(num) != seen.end()) {
            cout << "Duplicate found: " << num << endl;
            hasDuplicates = true;

            
        } else { //if not enter in seen array
            seen.insert(num);
        }
    }

    if (!hasDuplicates) {
        cout << "No duplicates found." << endl;
    }
}

int main() {
    vector<int> arr = {1, 5, 2, 3, 8, 9, 5}; 
    findDuplicates(arr);
    return 0;
}
