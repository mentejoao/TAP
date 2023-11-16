#include <iostream>

// Given is an integer N. Find the number of digits that N has in base K.
// Input is given from Standard Input in the following format:
// N K
// Output: Print the number of digits that 

int main() {
    int N, K;
    std::cin >> N >> K;

    int count = 0;
    while (N > 0) {
        N /= K;
        count++;
    }

    std::cout << count << std::endl;

    return 0;
}