int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int res = n;
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= target) {
                res = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return res;
    }
// int searchInsert(vector<int>& nums, int target) {
//         int idx = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
//         return idx;
//     }