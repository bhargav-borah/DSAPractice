#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "bhargav";
    map<char, int> mpp;
    for (int i = 0; i < s.size(); i++) {
        mpp[s[i]]++;
    }
    
    char q;
    cin >> q;
    cout << q << " appears " << mpp[q] << " times." << endl;

    // maps stores the keys in sorted order.
    for (auto it: mpp) {
        cout << it.first << " -> " << it.second << endl;
    }

    return 0;
}
