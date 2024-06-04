class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, right = 0;
        int maxFreq = 0;
        int maxLen = 0;
        unordered_map<char, int> mpp;

        while (right < s.length()) {
            mpp[s[right]]++;
            maxFreq = max(maxFreq, mpp[s[right]]);
            while ((right - left + 1) - maxFreq > k) {
                mpp[s[left]]--;

                maxFreq = 0;
                for (auto it: mpp) {
                    maxFreq = max(maxFreq, it.second);
                }

                left++;
            }

            if ((right - left + 1) - maxFreq <= k) {
                maxLen = max(maxLen, right - left + 1);
            }

            right++;
        }

        return maxLen;
    }
};