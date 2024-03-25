class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        int sum = 0;

        for (auto it: nums) {
            sum += it;
            maxi = max(maxi, sum);

            if (sum < 0) sum = 0;
        }

        // if (maxi < 0) return 0; -> only if we consider empty subarrays (with sum 0)
        return maxi;
    }
};