int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        int prefixSum = 0, count = 0;

        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            int otherSum = prefixSum - k;
            count += mpp[otherSum];
            mpp[prefixSum] += 1;
        }

        return count;
    }
// int subarraySum(vector<int>& nums, int k) {
//         int n = nums.size();
//         int count = 0;

//         for (int i = 0; i < n; i++) {
//             int sum = 0;
//             for (int j = i; j < n; j++) {
//                 sum += nums[j];
//                 if (sum == k) count++;
//             }
//         }

//         return count;
//     }