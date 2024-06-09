#include <bits/stdc++.h> 
int getLengthofLongestSubstring(string s, int k) {
    unordered_map<int, int> mpp;
    int left = 0, right = 0;
    int maxi = 0;

    while (right < s.length()) {
        mpp[s[right]]++;
        while (mpp.size() > k) {
            mpp[s[left]]--;
            if (mpp[s[left]] == 0) mpp.erase(s[left]);
            left++;
        }
        maxi = max(maxi, right - left + 1);
        right++;
    }

    return maxi;
}