#include <iostream>
#include <vector>

// You are given positive integers A, B.
// Find the Kth largest positive integer that divides both A and B
// The input guarantees that there exists such a number.

// Input example 1:
// 8 12 2
// Output:
// 2

// Input example 2:
// 100 50 4
// Output:
// 5

// Input example 3:
// 1 1 1
// Output:
// 1

int greater(int a, int b){
    return (b < a) ? b : a;
}

int main() {
    int A, B, K;
    std::cin >> A >> B >> K;

    std::vector<int> divisorsC;

    for (int i = 1; i <= greater(A, B); i++) {
        if (A % i == 0 && B % i == 0) {
            divisorsC.push_back(i);
        }
    }

    if (K <= divisorsC.size()) {
        std::cout << divisorsC[divisorsC.size() - K] << std::endl;
    }

    return 0;
}