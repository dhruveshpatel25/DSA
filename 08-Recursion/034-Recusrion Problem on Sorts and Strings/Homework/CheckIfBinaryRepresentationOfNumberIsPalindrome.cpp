/*Check If Binary Representation of a Number is Palindrome
Ninja is given an integer ‘N’. Ninja wants to find whether the binary representation of integer ‘N’ is palindrome or not.
A palindrome is a sequence of characters that reads the same backward as forward.
Ninja is busy with his training. Help Ninja in finding out whether the binary representation of ‘N’ is palindrome or not.
https://www.naukri.com/code360/problems/check-palindrome_920555*/

#include <iostream>
#include <string>
using namespace std;

// Helper function to convert number to binary string
string toBinary(int n) {
    if (n == 0)
        return "0";
    if (n == 1)
        return "1";
    return toBinary(n / 2) + char('0' + (n % 2));
}

// Recursive function to check if a string is palindrome
bool isPalindrome(const string &s, int left, int right) {

    // Base case: If pointers have crossed or are equal, it's a palindrome
    if (left >= right)
        return true;

    // If mismatch is found
    if (s[left] != s[right])
        return false;

    // Move pointers inward
    return isPalindrome(s, left + 1, right - 1);
}

// Function to check if binary representation of a number is palindrome
bool isBinaryPalindrome(int n) {

    // Convert number to binary string
    string binary = toBinary(n); 

    // Check if the binary string is palindrome
    return isPalindrome(binary, 0, binary.size() - 1); 
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (isBinaryPalindrome(n)) {
        cout << "The binary representation of " << n << " is a palindrome." << endl;
    } else {
        cout << "The binary representation of " << n << " is not a palindrome." << endl;
    }

    return 0;
}