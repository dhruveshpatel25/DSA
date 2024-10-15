#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

void findDuplicates(const vector<int>& arr) {
    unordered_set<int> seen;
    bool hasDuplicates = false;

    for (int num : arr) {
        if (seen.find(num) != seen.end()) {
            cout << "Duplicate found: " << num << endl;
            hasDuplicates = true;
        } else {
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
