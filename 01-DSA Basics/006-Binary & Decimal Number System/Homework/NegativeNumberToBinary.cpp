#include<iostream>
#include<math.h>
using namespace std;

int main(){

    int n;
    cout<<"Enter the negative no.: ";
    cin>>n;

    // Calculate the number of bits in the integer type (typically 32 for int on most systems)
    int numBits = sizeof(n)*8;

    // Create a mask with the most significant bit (MSB) set to 1
    // For a 32-bit integer, the mask will be 1000...000 (1 followed by 31 zeros)
    unsigned int mask=1<<(numBits-1);
    for(int i=0;i<numBits;i++){

        //Perform a bitwise AND between the number and the mask to isolate the current bit
        // If the result is non-zero, the bit is 1; otherwise, it's 0
        cout<<  ((n & mask) ? '1':'0');
        
        //right shift
        mask>>=1;
    }
}