#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int hash[26] = {0};
    
    string s;
    cin >> s;
    
    for (int i = 0; i < s.size(); i++) {
        hash[s[i] - 'a']++;
    }
    
    char q;
    cin >> q;
    
    cout << "Character " << q << " appears " << hash[q - 'a'] << " times." << endl;

    return 0;
}