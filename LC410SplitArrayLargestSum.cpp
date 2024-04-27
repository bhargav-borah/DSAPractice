class Solution {
public:
    int countPartitions(vector<int>& nums, int maxSum) {
        int partitions = 1;
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (sum + nums[i] <= maxSum) {
                sum += nums[i];
            }
            else {
                partitions++;
                sum = nums[i];
            }
        }

        return partitions;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (countPartitions(nums, mid) > k) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return low;
    }
};

// class Solution {
// public:
//     int countPartitions(vector<int>& nums, int maxSum) {
//         int countPartitions = 1;
//         int sum = 0;

//         for (int i = 0; i < nums.size(); i++) {
//             if (sum + nums[i] <= maxSum) {
//                 sum += nums[i];
//             }
//             else {
//                 countPartitions++;
//                 sum = nums[i];
//             }
//         }

//         return countPartitions;
//     }

//     int splitArray(vector<int>& nums, int k) {
//         int low = *max_element(nums.begin(), nums.end());
//         int high = accumulate(nums.begin(), nums.end(), 0);

//         for (int i = low; i <= high; i++) {
//             if (countPartitions(nums, i) == k) return i;
//         }

//         return low;
//     }
// };