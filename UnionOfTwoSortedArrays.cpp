// Optimal solution 
#include <bits/stdc++.h>
vector < int > sortedArray(vector < int > a, vector < int > b) {
    int i = 0;
    int j = 0;
    int idx = -1;
    vector<int> arr;
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            if (idx == -1 || arr[idx] != a[i]) {
                arr.push_back(a[i]);
                idx++;
            }
            i++;
        }
        else if (a[i] == b[j]) {
            if (idx == -1 || arr[idx] != a[i]) {
                arr.push_back(a[i]);
                idx++;
            }
            i++;
            j++;
        }
        else {
            if (idx == -1 || arr[idx] != b[j]) {
                arr.push_back(b[j]);
                idx++;
            }
            j++;
        }
    }
    if (i == a.size()) {
        while (j < b.size()) {
            if (arr[idx] != b[j]) {
                arr.push_back(b[j]);
                idx++;
            }
            j++;
        }
    }
    if (j == b.size()) {
        while (i < a.size()) {
            if (arr[idx] != b[j]) {
                arr.push_back(a[i]);
                idx++;
            }
            i++;
        }
    }

    return arr;
}

// Brute force
// vector < int > sortedArray(vector < int > a, vector < int > b) {
//     // Write your code here
//     set<int> st;
//     for (auto it: a) st.insert(it);
//     for (auto it: b) st.insert(it);
//     vector<int> arr;
//     for (auto it: st) arr.push_back(it);
//     return arr;
// }