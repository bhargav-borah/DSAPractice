#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int arr[5] = {1, 2, 1, 2, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    map<int, int> mpp;
    for (int i = 0; i < size; i++) {
        mpp[arr[i]]++;
    }
    
    int q;
    cin >> q;
    
    cout << q << " appears " << mpp[q] << " times." << endl;
    
    // map stores the keys in sorted order
    for (auto it: mpp) {
        cout << it.first << " -> " << it.second << endl;
    }
    
    return 0;
}