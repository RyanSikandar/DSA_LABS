#include <iostream>
using namespace std;

int main() {
    // Defines an integer array 'list' with 5 elements and initialize it
    int list[5] = {3, 6, 9, 12, 15};

    // Creates an integer pointer 'pArr' and points it to the 'list' array
    int *pArr = list;

    int i = 0;

    // Use a while loop to iterate through the 'list' array
    while (i != 5) {
        // Print the value pointed to by 'pArr' at index 'i'
        cout << *(pArr + i) << " ";
        
        // Increment 'i' to move to the next element in the array
        i++;
    }

    // The loop will print: 3 6 9 12 15 followed by a space

    return 0;
}
