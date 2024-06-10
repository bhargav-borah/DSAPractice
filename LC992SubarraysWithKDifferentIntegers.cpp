class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }

    int atMost(vector<int>& nums, int k) {
        int left = 0, right = 0;
        unordered_map<int, int> mpp;
        int count = 0;

        while (right < nums.size()) {
            mpp[nums[right]]++;
            while (mpp.size() > k) {
                mpp[nums[left]]--;
                if (mpp[nums[left]] == 0) mpp.erase(nums[left]);
                left++;
            }
            count += (right - left + 1);
            right++;
        }

        return count;
    }
};