 #include <bits/stdc++.h>
 using namespace std;

// Optimal Solution if array contains positive, 0, and negative elements.
 int longestSubarrayWithSumK(vector<int> a, long long k) {
    long long sum = 0;
    int maxLen = 0;
    map<long long, int> mpp;

    for (int i = 0; i < a.size(); i++) {
        sum += a[i];
        if (sum == k) maxLen = max(maxLen, i + 1);
        long long rem = sum - k;
        if (mpp.find(rem) != mpp.end()) {
            int len = i - mpp[rem];
            maxLen = max(maxLen, len);
        }
        if (mpp.find(sum) == mpp.end()) mpp[sum] = i;
    }

    return maxLen;
}

// Optimal solution if the array contains only non-negative elements
 int longestSubarrayWithSumK(vector<int> a, long long k) {
    long long sum = a[0];
    int maxLen = 0;
    int left = 0;
    int right = 0;
    while (right < a.size()) {
        if (sum == k) {
            maxLen = max(maxLen, right - left + 1);
            right++;
            if (right < a.size()) sum += a[right];
        }
        else if (sum < k) {
            right++;
            if (right < a.size()) sum += a[right];
        }
        else if (sum > k) {
            sum -= a[left];
            left++;
        }
    }
    return maxLen;
}