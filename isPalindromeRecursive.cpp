#include <iostream>
using namespace std;

bool isPalindrome(string s, int start, int end) {
    if (start == end) return true;
    if (s[start] != s[end]) return false;
    
    return isPalindrome(s, start + 1, end - 1);
}

int main() {
    
    string name = "racecar";
    cout << isPalindrome(name, 0, 6) << endl;
    
    return 0;
}