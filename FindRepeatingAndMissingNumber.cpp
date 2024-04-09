#include <bits/stdc++.h>
vector<int> findMissingRepeatingNumbers(vector<int> a) {
    int n = a.size();

    long long supposedSum = (n * 1LL * (n + 1)) / 2;
    long long actualSum = 0;

    long long supposedSquareSum = (n * 1LL * (n + 1) * (2 * n + 1)) / 6;
    long long actualSquareSum = 0;

    for (auto it : a) {
        actualSum += it;
        actualSquareSum += 1LL * it * it;
    }

    long long diff = supposedSum - actualSum;
    long long sum = (supposedSquareSum - actualSquareSum) / diff;

    int repeating = (sum - diff) / 2;
    int missing = (sum + diff) / 2;

    return {repeating, missing};
}// vector<int> findMissingRepeatingNumbers(vector < int > a) {
//     int n = a.size();
//     unordered_map<int, int> mpp;
//     for (auto it: a) {
//         mpp[it]++;
//     }

//     int missing = -1, repeating = -1;
//     for (int i = 1; i <= n; i++) {
//         if (mpp.find(i) == mpp.end()) missing = i;
//         else if (mpp[i] == 2) repeating = i;

//         if (missing != -1 && repeating != -1) break;
//     }

//     return {repeating, missing};
// }
// vector<int> findMissingRepeatingNumbers(vector < int > a) {
//     int n = a.size();
//     int supposedSum = n * (n + 1) / 2;
//     int actualSum = 0;
//     set<int> st;
//     for (auto it: a) {
//         actualSum += it;
//         st.insert(it);
//     }

//     int missing, repeating;

//     for (int i = 1; i <= n; i++) {
//         if (st.find(i) == st.end()) missing = i;
//     }

//     repeating = missing - (supposedSum - actualSum);

//     return {repeating, missing};
// }