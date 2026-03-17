#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n <= 1) return n; // Base case: 0 and 1
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n = 10;
    for (int i = 0; i < n; i++) {
        cout << fibonacci(i) << " ";
    }
    return 0;
}