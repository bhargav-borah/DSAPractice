class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int maxLen = 0;
        int zeros = 0;

        while (right < nums.size()) {
            if (nums[right] == 0) zeros++;
            if (zeros > k) {
                if (nums[left] == 0) zeros--;
                left++;
            }
            if (zeros <= k) {
                maxLen = max(maxLen, right - left + 1);
            }
            right++;
        } 

        return maxLen;
    }
};