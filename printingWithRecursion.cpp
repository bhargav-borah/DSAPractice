#include <iostream>
using namespace std;

void printName(string s, int N) {
    if (N == 0) return;
    cout << s << endl;
    printName(s, N - 1);
}

void printNum(int i, int N) {
    if (i > N) return;
    cout << i << endl;
    printNum(i + 1, N);
}

void printNumReverse(int i) {
    if (i <= 0) return;
    cout << i << endl;
    printNumReverse(i - 1);
}

void printNumBacktrack(int i) {
    if (i <= 0) return;
    printNumBacktrack(i - 1);
    cout << i << endl;
}

void printNumReverseBacktrack(int i, int N) {
    if (i > N) return;
    printNumReverseBacktrack(i + 1, N);
    cout << i << endl;
}

int main() {
    
    // printName("Bhargav", 5);
    // printNum(1, 5);
    // printNumReverse(5);
    // printNumBacktrack(5);
    printNumReverseBacktrack(1, 5);
    
    return 0;
}