#include <iostream>
#include <vector>
#include <climits>

int main() {
    std::cout << "Testing sanitizers...\n";

    // --- AddressSanitizer test: heap buffer overflow ---
    int* arr = new int[5];
    arr[5] = 42; // ⚠️ out-of-bounds write
    delete[] arr;

    // --- UndefinedBehaviorSanitizer test: use of uninitialized variable ---
    int x;
    if (x == 0) { // ⚠️ x is uninitialized
        std::cout << "x is zero\n";
    }

    // --- UBSan: signed integer overflow ---
    int a = INT_MAX;
    int b = a + 1; // ⚠️ signed overflow
    std::cout << "b = " << b << "\n";

    // --- UBSan: null pointer dereference ---
    int* p = nullptr;
    *p = 10; // ⚠️ undefined behavior

    return 0;
}
