class Solution {
public:
    int numberOfSubstrings(string s) {
        int left = 0, right = 0;
        vector<int> count(3, 0);
        int res = 0;

        while (right < s.size()) {
            count[s[right] - 'a']++;
            while (count[0] && count[1] && count[2]) {
                res += (s.size() - right);
                count[s[left] - 'a']--;
                left++;
            }
            right++;
        }

        return res;
    }
};