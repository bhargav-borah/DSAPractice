class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return numSubarraysWithSumAtMost(nums, goal) - numSubarraysWithSumAtMost(nums, goal - 1);
    }

    int numSubarraysWithSumAtMost(vector<int>& nums, int goal) {
        if (goal < 0) return 0;

        int count = 0;
        int sum = 0;
        int left = 0, right = 0;

        while (right < nums.size()) {
            sum += nums[right];
            while (sum > goal) {
                sum -= nums[left];
                left++;
            }

            count += (right - left + 1);

            right++;
        }

        return count;
    }
};

// class Solution {
// public:
//     int numSubarraysWithSum(vector<int>& nums, int goal) {
//         int count = 0;

//         for (int i = 0; i < nums.size(); i++) {
//             int sum = 0;
//             for (int j = i; j < nums.size(); j++) {
//                 sum += nums[j];
//                 if (sum == goal) count++;
//             }
//         }

//         return count;
//     }
// };