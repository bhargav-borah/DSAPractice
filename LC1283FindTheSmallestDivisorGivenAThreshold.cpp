int calculateSum(vector<int>& nums, int divisor) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += ceil((double)nums[i] / divisor);
        }

        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int low = 1;
        int high = INT_MIN;
        for (int i = 0; i < n; i++) {
            high = max(high, nums[i]);
        }

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (calculateSum(nums, mid) <= threshold) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
// int calculateSum(vector<int>& nums, int divisor) {
//         int n = nums.size();
//         int sum = 0;
//         for (int i = 0; i < n; i++) {
//             sum += ceil(double(nums[i]) / divisor);
//         }

//         return sum;
//     }
    
//     int smallestDivisor(vector<int>& nums, int threshold) {
//         int n = nums.size();
//         int low = 1;
//         int high = INT_MIN;
//         for (int i = 0; i < n; i++) {
//             high = max(high, nums[i]);
//         }

//         for (int i = low; i <= high; i++) {
//             if (calculateSum(nums, i) <= threshold) return i;
//         }

//         return -1;
//     }