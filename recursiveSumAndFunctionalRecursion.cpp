#include <iostream>
using namespace std;

void recursiveSum1(int i, int sum) {
    if (i < 1) {
        cout << sum << endl;
        return;
    }
    recursiveSum1(i - 1, sum + i);
}

int recursiveSum2(int n) {
    if (n == 1) return 1;
    if (n <= 0) return 0;
    
    return n + recursiveSum2(n - 1);
}

int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

int main() {
    // recursiveSum1(5, 0);
    // cout << recursiveSum2(5) << endl;
    cout << factorial(6) << endl;
    
    return 0;
}