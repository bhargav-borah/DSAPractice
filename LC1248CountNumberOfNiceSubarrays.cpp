class Solution {
public:
    int numberOfSubarrays(vector<int>&nums, int k) {
        return numberOfSubarraysAtMost(nums, k) - numberOfSubarraysAtMost(nums, k - 1);
    }

    int numberOfSubarraysAtMost(vector<int>& nums, int k) {
        if (k < 0) return 0;

        int count = 0;
        int sum = 0;
        int left = 0, right = 0;

        while (right < nums.size()) {
            sum += (nums[right] % 2);
            while (sum > k) {
                sum -= (nums[left] % 2);
                left++;
            }
            count += (right - left + 1);
            right++;
        }

        return count;
    }
};