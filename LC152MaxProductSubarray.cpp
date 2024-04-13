int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int prefix = 1, suffix = 1;
        int res = INT_MIN;
        
        for (int i = 0; i < n; i++) {
            if (prefix == 0) prefix = 1;
            if (suffix == 0) suffix = 1;

            prefix *= nums[i];
            suffix *= nums[n - i - 1];

            res = max(res, max(prefix, suffix));
        }

        return res;
    }

    // int maxProduct(vector<int>& nums) {
    //     int n = nums.size();
    //     int maxi = INT_MIN;

    //     for (int i = 0; i < n; i++) {
    //         int prod = 1;
    //         for (int j = i; j < n; j++) {
    //             prod *= nums[j];
    //             maxi = max(prod, maxi);
    //         }
    //     }

    //     return maxi;
    // }