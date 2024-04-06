#include <bits/stdc++.h>
int subarraysWithSumK(vector < int > a, int b) {
    int n = a.size();
    int xorVal = 0;
    unordered_map<int, int> mpp;
    mpp[xorVal]++; // {0 -> 1}
    int count = 0;

    for (int i = 0; i < n; i++) {
        xorVal ^= a[i];
        count += mpp[xorVal ^ b];
        mpp[xorVal]++;
    }

    return count;
}

// int subarraysWithSumK(vector < int > a, int b) {
//     int n = a.size();
//     int count = 0;

//     for (int i = 0; i < n; i++) {
//         int xorVal = 0;
//         for (int j = i; j < n; j++) {
//             xorVal ^= a[j];
//             if (xorVal == b) count++;
//         }

//     }

//     return count;
// }