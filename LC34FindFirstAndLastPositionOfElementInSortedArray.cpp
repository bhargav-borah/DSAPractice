int getLowerBound(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;
        int res = n;

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

    int getUpperBound(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;
        int res = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > target) {
                res = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return res;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return {-1, -1};

        int starting = getLowerBound(nums, target);
        int ending = getUpperBound(nums, target) - 1;

        if (starting == nums.size() || nums[starting] != target) {
            return {-1, -1};
        }

        return {starting, ending};
    }
// vector<int> searchRange(vector<int>& nums, int target) {
//         if (nums.size() == 0) return {-1, -1};
//         int starting = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
//         int ending = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;

//         if (starting == nums.size() || nums[starting] != target) {
//             return {-1, -1};
//         }

//         return {starting, ending};
//     }

