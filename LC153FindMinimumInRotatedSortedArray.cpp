int findMin(vector<int>& nums) {
        int low = 0, high = nums.size();
        int mini = INT_MAX;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[low] <= nums[mid]) { // when left half of search space is sorted
                mini = min(mini, nums[low]);
                low = mid + 1;
            }   
            else {                        // when right half of search space is sorted
                mini = min(mini, nums[mid]);
                high = mid - 1;
            }
        }

        return mini;
    }