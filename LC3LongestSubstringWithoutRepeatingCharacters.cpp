class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<int> st;
        int left = 0, right = 0;
        int maxi = 0;

        while (right < s.length()) {
            if (st.find(s[right]) == st.end()) {
                st.insert(s[right]);
                maxi = max(maxi, right - left + 1);
                right++;
            }
            else {
                st.erase(s[left]);
                left++;
            }
        }

        return maxi;
    }
};